#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  sort(A.begin(), A.end());
  int M = N - 1;
  vector<long long> D(M);
  for (int i = 0; i < M; i++) {
    D.at(i) = A.at(i + 1) - A.at(i);
  }
  int L = N - K - 1;

  if (L == 0) {  // 1個しか残らない時
    cout << 0 << endl;
    return 0;
  }
  

  // Dの連続するL個の和の最小値を求める
  // 初期値
  long long now = 0;
  for (int i = 0; i < L; i++) {
    now += D[i];
  }
  long long ans = now;

  for (int i = 1; i <= M - L; i++) {
    now = now - D.at(i - 1) + D.at(i + L - 1);
    ans = min(ans, now);
  }

  cout << ans << endl;
  return 0;
}
