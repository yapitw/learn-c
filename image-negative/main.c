#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *fIn = fopen("girlface.bmp", "rb");
  FILE *fOut = fopen("girlface_negative.bmp", "wb");

  unsigned char *imageData;
  unsigned char *newImageData;
  unsigned char imageHeader[54];
  unsigned char colorTable[1024];

  fread(imageHeader, sizeof(unsigned char), 54, fIn);

  int width = *(int *)&imageHeader[22];
  int height = *(int *)&imageHeader[18];
  int bitDepth = *(int *)&imageHeader[28];

  int imageDataSize = width * height;

  imageData = (unsigned char *)malloc(imageDataSize * sizeof(unsigned char));
  newImageData = (unsigned char *)malloc(imageDataSize * sizeof(unsigned char));

  if (bitDepth <= 8) {
    fread(colorTable, sizeof(unsigned char), 1024, fIn);
  }
  fread(imageData, sizeof(unsigned char), imageDataSize, fIn);

  for (int i = 0; i < height; i++) {

    for (int j = 0; j < width; j++) {
      newImageData[i * width + j] = 255 - imageData[i * width + j];
    }
  }

  fwrite(imageHeader, sizeof(unsigned char), 54, fOut);
  if (bitDepth <= 8) {
    fwrite(colorTable, sizeof(unsigned char), 1024, fOut);
  }
  fwrite(newImageData, sizeof(unsigned char), imageDataSize, fOut);

  printf("SUCCESS!\n");

  fclose(fIn);
  fclose(fOut);
  return 0;
}