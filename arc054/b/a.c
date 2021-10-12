/* https://atcoder.jp/contests/arc054/tasks/arc054_b */

#include <math.h>
#include <stdio.h>

int main() {
  double P;
  scanf("%lf", &P);
  double x = -1.5 * log(1.5 / (P * log(2))) / log(2);
  if (x < 0) {
    x = 0;
  }
  double ans = x + P / pow(2, x / 1.5);
  printf("%.15lf\n", ans);
  return 0;
}
