int main() {
  int v[3] = {1, 2, 3};
  int *p[3] = {&v[0], &v[1], &v[2]};

  int i;
  for (i = 0; i < 3; i++) {
    *p[i] = 0;
  }

  *p[2] = 5;
}