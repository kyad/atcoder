#include <stdio.h>

int main() {
  char a, b, c;
  int x, y, z;
  scanf("%c%c%c\n", &a, &b, &c);
  x = a - '0';
  y = b - '0';
  z = c - '0';
  printf("%d\n", x + y + z);
  return 0;
}
