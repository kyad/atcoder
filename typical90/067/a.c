#include <stdio.h>

long long f(long long n) {
  long long ans = 0;
  long long b = 1;
  while (n > 0) {
    long long r = n % 9;
    if (r == 8) {
      r = 5;
    }
    ans += r * b;
    b *= 8;
    n /= 9;
  }
  return ans;
}

int main() {
  long long N;
  int K;
  scanf("%llo %d", &N, &K);
  for (int k = 0; k < K; k++) {
    N = f(N);
  }
  printf("%llo\n", N);
  return 0;
}
