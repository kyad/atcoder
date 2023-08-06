#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N + 1, -1);
  vector<int> memo(N + 1, -1);
  auto sub = [&](int shift) {
    // A[shift] から A[shift]+KまでのK+1個の和sumを求める。
    int sum = 0;
    for (int i = 0; i < K + 1; i++) {
      // 1 query
      cout << '?';
      for (int k = 0; k < K; k++) {
        const int j = (i + k) % (K + 1) + shift;
        cout << ' ' << j;
      }
      cout << endl;
      int T;
      cin >> T;
      if (T < 0) {
        exit(1);
      }
      memo[shift + i] = T;
      sum = (sum + T) % 2;
    }
    // A[shift+i]を求める
    for (int i = 0; i < K + 1; i++) {
      const int j = shift + (i + 1) % (K + 1);  // shift+iの次
      A[shift + i] = (sum + memo[j]) % 2;
    }
  };
  const int M = N / (K + 1);
  for (int m = 0; m < M; m++) {
    const int shift = 1 + m * (K + 1);
    sub(shift);
  }

  // 残り (M * (K + 1) + 1) ... N
  int sum = 0;
  for (int i = 1; i <= K - 1; i++) {
    sum += A[i];
  }
  for (int i = (M * (K + 1) + 1); i <= N; i++) {
    // A[i]を求める
    cout << "? " << i;
    for (int k = 1; k <= K - 1; k++) {
      cout << ' ' << k;
    }
    cout << endl;
    int T;
    cin >> T;
    if (T < 0) {
      exit(1);
    }
    A[i] = (sum + T) % 2;
  }

  cout << '!';
  for (int i = 1; i <= N; i++) {
    cout << ' ' << A[i];
  }
  cout << endl;
  return 0;
}
