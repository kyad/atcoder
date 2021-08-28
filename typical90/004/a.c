/* https://atcoder.jp/contests/typical90/tasks/typical90_d */

#include <stdio.h>
#include <stdlib.h>

int main() {
  int h, w;
  int *a = 0;
  int *b = 0;
  int a0[2000];
  int a1[2000];
  int i, j;
  scanf("%d %d", &h, &w);
  a = (int *)malloc(sizeof(int) * h * w);
  b = (int *)malloc(sizeof(int) * h * w);
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      scanf("%d ", &a[i * w + j]);
    }
  }
  for (j = 0; j < w; j++) {
    a0[j] = 0;
    for (i = 0; i < h; i++) {
      a0[j] += a[i * w + j];
    }
  }
  for (i = 0; i < h; i++) {
    a1[i] = 0;
    for (j = 0; j < w; j++) {
      a1[i] += a[i * w + j];
    }
  }
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      b[i * w + j] = a0[j] + a1[i] - a[i * w + j];
    }
  }
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      printf("%d%c", b[i * w + j], j == w - 1 ? '\n' : ' ');
    }
  }
  free(a);
  free(b);
  return 0;
}
