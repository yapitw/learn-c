#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fIn = fopen("cameraman.bmp", "rb");
  FILE *fOut = fopen("cameraman_rotated.bmp", "wb");
  int select;

  unsigned char imgHeader[54];
  unsigned char colorTable[1024];

  if (fIn == NULL) {
    printf("Unabled  to open file\n");
  }

  for (int i = 0; i < 54; i++) {
    imgHeader[i] = getc(fIn);
  }
  fwrite(imgHeader, sizeof(unsigned char), 54, fOut);

  int height = *(int *)&imgHeader[22];
  int width = *(int *)&imgHeader[18];
  int bitDepth = *(int *)&imgHeader[28];

  if (bitDepth <= 8) {
    fread(colorTable, sizeof(unsigned char), 1024, fIn);
    fwrite(colorTable, sizeof(unsigned char), 1024, fOut);
  }

  int imgSize = height * width;

  unsigned char buffer[width][height];
  unsigned char out_buffer[width][height];

  fread(buffer, sizeof(unsigned char), imgSize, fIn);

  printf("Enter rotation direction: \n");
  printf("1: Rotate right \n");
  printf("2: Rotate left \n");
  printf("3: Rotate 180\n");

  scanf("%d", &select);

  switch (select) {
  case 1:
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        out_buffer[j][height - 1 - i] = buffer[i][j];
      }
    }
    break;

  case 2:
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        out_buffer[j][i] = buffer[i][j];
      }
    }
    break;

  case 3:
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        out_buffer[width - i][j] = buffer[i][j];
      }
    }
    break;

  default:
    break;
  }

  fwrite(out_buffer, sizeof(unsigned char), imgSize, fOut);
  printf("SUCCESS");

  fclose(fIn);
  fclose(fOut);

  return 0;
}