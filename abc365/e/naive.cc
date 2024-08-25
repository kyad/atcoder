#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
  int N;
  cin >> N;
  vector<long long> A(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }
  vector<long long> S(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    S.at(i) = S.at(i - 1) ^ A.at(i);
  }
  vector<long long> T(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    T.at(i) = T.at(i - 1) + S.at(i);
  }
  vector<long long> U(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    U.at(i) = U.at(i - 1) + T.at(i);
  }
  long long ans = 0;
  // naive
  for (int i = 1; i <= N - 1; i++) {
    for (int j = i + 1; j <= N; j++) {
      ans += S.at(j) ^ S.at(i - 1);
    }
  }
  cout << ans << endl;
  return 0;
}
