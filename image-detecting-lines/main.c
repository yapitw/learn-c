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

void line_detector(unsigned char* _inputImgData, unsigned char* _outputImgData,
                   int imgCols, int imgRows, int MASK[3][3]);

struct lineMask;
signed char* tmp;

int main() {
  int imgWidth, imgHeight, imgBitDepth;
  unsigned char imgHeader[BMP_HEADER_SIZE];
  unsigned char imgColorTable[BMP_COLOR_TABLE_SIZE];
  unsigned char imgBuffer[CUSTOM_IMG_SIZE];
  unsigned char imgBuffer2[CUSTOM_IMG_SIZE];

  const char imgName[]    = "lena512.bmp";
  const char newImgName[] = "lena_ver.bmp";

  int VER[3][3] = {
      {-1, 2, -1}, //
      {-1, 2, -1}, //
      {-1, 2, -1}  //
  };

  int HOR[3][3] = {
      {-1, -1, -1}, //
      {2, 2, 2},    //
      {-1, -1, -1}  //
  };

  int LDIA[3][3] = {
      {2, -1, -1}, //
      {-1, 2, -1}, //
      {-1, -1, 2}  //
  };

  int RDIA[3][3] = {
      {-1, -1, 2}, //
      {-1, 2, -1}, //
      {2, -1, -1}  //
  };

  imageReader(imgName, &imgHeight, &imgWidth, &imgBitDepth, &imgHeader[0],
              &imgColorTable[0], &imgBuffer[0]);

  line_detector(&imgBuffer[0], &imgBuffer2[0], imgWidth, imgHeight, VER);
  imageWriter(newImgName, imgHeader, imgColorTable, imgBuffer2, imgBitDepth);

  line_detector(&imgBuffer[0], &imgBuffer2[0], imgWidth, imgHeight, HOR);
  imageWriter("lena_hor.bmp", imgHeader, imgColorTable, imgBuffer2, imgBitDepth);

  line_detector(&imgBuffer[0], &imgBuffer2[0], imgWidth, imgHeight, LDIA);
  imageWriter("lena_ldia.bmp", imgHeader, imgColorTable, imgBuffer2, imgBitDepth);

  line_detector(&imgBuffer[0], &imgBuffer2[0], imgWidth, imgHeight, RDIA);
  imageWriter("lena_rdia.bmp", imgHeader, imgColorTable, imgBuffer2, imgBitDepth);

  printf("SUCCESS! \n");

  return 0;
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

void line_detector(unsigned char* _inputImgData, unsigned char* _outputImgData,
                   int imgCols, int imgRows, int MASK[][3]) {
  int x, y, i, j, sum;

  for (y = 1; y <= imgRows; y++) {
    for (x = 1; x <= imgCols; x++) {

      sum = 0;
      for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
          sum = sum + *(_inputImgData + x + i + (long)(y + j) * imgCols) *
                          MASK[i + 1][j + 1];
        }
      }
      if (sum > 255) {
        sum = 255;
      }
      if (sum < 0) {
        sum = 0;
      }
      *(_outputImgData + x + (long)y * imgCols) = sum;
    }
  }
}