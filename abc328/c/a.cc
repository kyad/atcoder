#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/**
 * AをAの累積和に置き換える。
 * 計算量はO(N)
 */
template<class T> void cumsum(vector<T>& A) {
  int N = A.size();
  for (int i = 1; i < N; i++) {
    A[i] += A[i - 1];
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  S.insert(0, "_");
  assert((int)S.size() == N + 1);
  vector<int> A(N + 1, 0);
  for (int i = 1; i <= N - 1; i++) {
    if (S.at(i) == S.at(i + 1)) {
      A.at(i) = 1;
    }
  }
  cumsum(A);
  for (int qi = 0; qi < Q; qi++) {
    int l, r;
    cin >> l >> r;
    int ans = A.at(r - 1) - A.at(l - 1);
    cout << ans << '\n';
  }
  return 0;
}
