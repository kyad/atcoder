#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long g(long long K) {
  if (K % 2 == 1) {
    return K - 1;
  } else {
    return K + 1;
  }
}

long long f(long long N, long long K) {
  assert(K >= 0 && K < N);
  if (N % 2 == 1) {
    if (K > 0) {
      K = f(N - 1, K - 1) + 1;
    }
    if (K < N - 1) {
      K = f(N - 1, K);
    }
    return K;
  }
  // Nは偶数
  int bit = 60;
  for (bit = 60; bit >= 0; bit--) {
    if ((N>>bit)&1) {
      break;
    }
  }
  assert(bit >= 1);
  long long M = (1LL<<bit);
  long long ans;
  if (N == M) {
    ans = g(K);
  } else if (K < N - M) {
    ans = f(N - M, K);
  } else if (K < M) {
    ans = K;
  } else {
    ans = f(N - M, K - M) + M;
  }
  return ans;
}

void testcase() {
  long long N, K;
  cin >> N >> K;
  K--;
  long long ans = f(N, K);
  cout << (ans + 1) << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
