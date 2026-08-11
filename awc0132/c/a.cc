#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> P(N), D(N);
  for (int i = 0; i < N; i++) {
    cin >> P.at(i) >> D.at(i);
  }
  vector<long long> S(D);
  for (int i = 1; i < N; i++) {
    S.at(i) += S.at(i - 1);
  }
  for (int i = 1; i < N; i++) {
    P.at(i) -= S.at(i - 1);
  }
  for (int i = 1; i < N; i++) {
    if (P.at(i) > P.at(i - 1)){
      P.at(i) = P.at(i - 1);
    }
  }
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    A.at(i) = -P.at(i);
  }
  for (int qi = 0; qi < Q; qi++) {
    long long S;
    cin >> S;
    int ans = upper_bound(A.begin(), A.end(), -S) - A.begin();
    cout << ans << '\n';
  }
  return 0;
}
