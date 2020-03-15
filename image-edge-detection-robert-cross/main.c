#include "mask.h"
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54
#define BMP_COLOR_TABLE_SIZE 1024
#define CUSTOM_IMG_SIZE 512 * 512

void imageReader(const char* imgName, int* _height, int* _width, int* _bitDepth,
                 unsigned char* _header, unsigned char* _colorTable,
                 unsigned char* _buf);

void imageWriter(const char* imgName, unsigned char* header,
                 unsigned char* colorTable, unsigned char* buf, int bitDepth);

void Convolve(int imgRows, int imgCols, struct Mask* myMask,
              unsigned char* input_buf, unsigned char* output_buf);

int main() {
  int imgWidth, imgHeight, imgBitDepth;
  unsigned char imgHeader[BMP_HEADER_SIZE];
  unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
  unsigned char imgBuffer[CUSTOM_IMG_SIZE];
  unsigned char imgBuffer2[CUSTOM_IMG_SIZE];

  const char imgName[]    = "lena512.bmp";
  const char newImgName[] = "lena_rb_gy.bmp";

  struct Mask rbMask;
  signed char* tmp;
  int i;

  rbMask.Cols = rbMask.Rows = 2;
  rbMask.Data               = (unsigned char*)malloc(4);

  /* Robert Gx
    1,  0
    0, -1
  */

  int robert_msk_gx[] = {1, 0, 0, -1};

  /* Robert Gy
    0,  1
    -1, 0
  */

  int robert_msk_gy[] = {0, 1, -1, 0};

  tmp = (signed char*)rbMask.Data;

  for (i = 0; i < 4; i++) {
    *tmp = robert_msk_gy[i];
    ++tmp;
  }

  imageReader(imgName, &imgHeight, &imgWidth, &imgBitDepth, &imgHeader[0],
              &imgColorTable[0], &imgBuffer[0]);

  Convolve(imgHeight, imgWidth, &rbMask, imgBuffer, imgBuffer2);
  imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth);
  printf("SUCCESS! \n");

  return 0;
}

void Convolve(int imgRows, int imgCols, struct Mask* myMask,
              unsigned char* input_buf, unsigned char* output_buf) {

  long i, j, n, m, idx, jdx;
  int ms, im, val;
  unsigned char* temp;

  for (i = 0; i < imgRows; ++i) {
    for (j = 0; j < imgCols; ++j) {
      val = 0;
      for (m = 0; m < myMask->Rows; ++m) {
        for (n = 0; n < myMask->Cols; ++n) {
          ms  = (signed char)*(myMask->Data + m * myMask->Rows + n);
          idx = i - m;
          jdx = j - n;
          if (idx >= 0 && jdx >= 0) {
            im = *(input_buf + idx * imgRows + jdx);
          }
          val += ms * im;
        }
      }
      if (val > 255) {
        val = 255;
      }
      if (val < 0) {
        val = 0;
      }
      temp  = output_buf + i * imgRows + j;
      *temp = (unsigned char)val;
    }
  }
}

void imageReader(               //
    const char* imgName,        //
    int* _height,               //
    int* _width,                //
    int* _bitDepth,             //
    unsigned char* _header,     //
    unsigned char* _colorTable, //
    unsigned char* _buf) {
  int i;
  FILE* streamIn;
  streamIn = fopen(imgName, "rb");
  if (streamIn == (FILE*)0) {
    printf("Unable to read image \n");
  }

  for (i = 0; i < 54; i++) {
    _header[i] = getc(streamIn);
  }

  *_width    = *(int*)&_header[18];
  *_height   = *(int*)&_header[22];
  *_bitDepth = *(int*)&_header[28];

  if (*_bitDepth <= 8) {
    fread(_colorTable, sizeof(unsigned char), 1024, streamIn);
  }

  fread(_buf, sizeof(unsigned char), CUSTOM_IMG_SIZE, streamIn);
  fclose(streamIn);
}

void imageWriter(              //
    const char* imgName,       //
    unsigned char* header,     //
    unsigned char* colorTable, //
    unsigned char* buf,        //
    int bitDepth) {
  FILE* fo = fopen(imgName, "wb");
  fwrite(header, sizeof(unsigned char), 54, fo);
  if (bitDepth <= 8) {
    fwrite(colorTable, sizeof(unsigned char), 1024, fo);
  }
  fwrite(buf, sizeof(unsigned char), CUSTOM_IMG_SIZE, fo);
  fclose(fo);
}