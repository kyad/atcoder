#include <cassert>
#include <iostream>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
  int N, K;
  cin >> N >> K;
  int A[10];
  auto f = [&](auto f, int n, int k) -> void {
    if (n == 1) {
      if (k % N == 0) {
        A[N - 1] = k / N;
        for (int i = 0; i < N; i++) {
          printf("%d ", A[i]);
        }
        putchar('\n');
      }
      return;
    }
    int i = N - n;
    if (k >= 1 && i + 1 > k) {
      return;
    }
    for (int a = 0; a <= k / (i + 1); a++) {
      A[i] = a;
      f(f, n - 1, k - a * (i + 1));
    }
  };
  f(f, N, K);
  return 0;
}
