#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b) {
  return *(int *)b - *(int *)a;
}

int main() {
  int n;
  int a[100];
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d ", &a[i]);
  }
  qsort(a, n, sizeof(int), compare);
  int alice = 0;
  int bob = 0;
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      alice += a[i];
    } else {
      bob += a[i];
    }
  }
  printf("%d\n", alice - bob);
  return 0;
}
