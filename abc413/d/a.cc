#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Return sign(x). If x == 0, then return 0.
template<typename T> T sign(T x) {
  return x > 0 ? 1 : x < 0 ? -1 : 0;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A.at(i);
    }
    vector<pair<long long, long long> > B(N);
    for (int i = 0; i < N; i++) {
      B.at(i).first = abs(A.at(i));
      B.at(i).second = sign(A.at(i));
    }

    // A[i]の絶対値が全て同じか確認
    bool issame = true;
    for (int i = 1; i < N; i++) {
      if (B.at(i).first != B.at(0).first) {
        issame = false;
      }
    }

    if (issame) {
      // A[i]の絶対値が全て同じ時
      bool ans = false;
      int plus = 0;
      int minus = 0;
      for (int i = 0; i < N; i++) {
        if (B.at(i).second == 1) {
          plus++;
        } else {
          minus++;
        }
      }
      // 公比が1
      if (plus == N || minus == N) {
        ans = true;
      }
      // 公比が-1
      if (max(plus, minus) == (N + 1) / 2 && min(plus, minus) == N / 2) {
        ans = true;
      }
      cout << (ans ? "Yes" : "No") << '\n';
    } else {
      sort(B.begin(), B.end());
      vector<long long> C(N);
      for (int i = 0; i < N; i++) {
        C.at(i) = B.at(i).first * B.at(i).second;
      }
      bool ok = true;
      for (int i = 1; i <= N - 2; i++) {
        long long left = C.at(i) * C.at(i);
        long long right = C.at(i - 1) * C.at(i + 1);
        if (left != right) {
          ok = false;
        }
      }
      cout << (ok ? "Yes" : "No") << '\n';
    }
  }
  return 0;
}
