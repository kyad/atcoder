#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<long long> L(A);
  for (int i = 1; i < N; i++) {
    L.at(i) += L.at(i - 1);
  }
  vector<long long> R(A);
  for (int i = N - 2; i >= 0; i--) {
    R.at(i) += R.at(i + 1);
  }
  const long long INF = 4e18;
  long long ans = INF;
  for (int k = 0; k <= N - 2; k++) {
    long long now = abs(L.at(k) - R.at(k + 1));
    ans = min(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
