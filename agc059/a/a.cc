// https://atcoder.jp/contests/agc059/tasks/agc059_a

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> A(N, 0);
  for (int i = 1; i < N; i++) {
    if (S[i - 1] != S[i]) {
      A[i] = 1;
    }
  }
  vector<int> sum(N, 0);
  for (int i = 1; i < N; i++) {
    sum[i] = sum[i - 1] + A[i];
  }
  for (int q = 0; q < Q; q++) {
    int L, R;
    cin >> L >> R;
    L--; R--;
    int k = sum[R] - sum[L];
    // 両端に...A, A...を付ける処理
    if (S[L] != S[R]) {
      k++;
    }
    int ans = ceildiv(k, 2);
    cout << ans << '\n';
  }
  return 0;
}
