#include <stdio.h>
#include <stdlib.h>

#define BRIGHTNESS_FACTOR 50
#define MAX_COLOR 255
#define MIN_COLOR 0

int main() {
  FILE *fIn = fopen("images/lena512.bmp", "rb");
  FILE *fOut = fopen("images/lena_bright.bmp", "wb");

  unsigned char imgHeader[54];
  unsigned char colorTable[1024];

  if (fIn == NULL) {
    printf("Unabled to read image");
  }

  for (int i = 0; i < 54; i++) {
    imgHeader[i] = getc(fIn);
  }

  fwrite(imgHeader, sizeof(unsigned char), 54, fOut);

  int height = *(int *)&imgHeader[22];
  int width = *(int *)&imgHeader[18];
  int bitDepth = *(int *)&imgHeader[28];

  int imgSize = height * width;

  if (bitDepth <= 8) {
    fread(colorTable, sizeof(unsigned char), 1024, fIn);
    fwrite(colorTable, sizeof(unsigned char), 1024, fOut);
  }

  unsigned char buffer[imgSize];

  fread(buffer, sizeof(unsigned char), imgSize, fIn);
  int temp;
  for (int i = 0; i < imgSize; i++) {
    temp = buffer[i] + BRIGHTNESS_FACTOR;
    if (BRIGHTNESS_FACTOR > 0)
      buffer[i] = (temp > MAX_COLOR) ? MAX_COLOR : temp;
    if (BRIGHTNESS_FACTOR < 0)
      buffer[i] = (temp < MIN_COLOR) ? MIN_COLOR : temp;
  }
  fwrite(buffer, sizeof(unsigned char), imgSize, fOut);
  fclose(fIn);
  fclose(fOut);

  return 0;
}