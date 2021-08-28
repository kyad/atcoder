#include <stdio.h>

int main() {
  int n;
  int a[200];
  scanf("%d", &n);
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d ", &a[i]);
  }
  int ans = 0;
  while (1) {
    int ok = 1;
    for (i = 0; i < n; i++) {
      if (a[i] % 2 == 1) {
	ok = 0;
	break;
      }
    }
    if (ok) {
      ans++;
      for (i = 0; i < n; i++) {
	a[i] = a[i] / 2;
      }
    } else {
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
