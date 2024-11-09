#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> X(M);
  for (int j = 0; j < M; j++) {
    cin >> X.at(j);
  }
  vector<int> A(M);
  for (int j = 0; j < M; j++) {
    cin >> A.at(j);
  }
  vector<pair<int, int> > P(M + 1);
  for (int j = 0; j < M; j++) {
    P.at(j) = make_pair(X.at(j), A.at(j));
  }
  P.at(M) = make_pair(N + 1, 0);
  sort(P.begin(), P.end());

  if (P.at(0).first != 1) {
    cout << -1 << endl;
    return 0;
  }

  long long ans = 0;
  long long rem = 0;  // 残り
  for (int j = 0; j < M; j++) {
    long long x = P.at(j).first;
    long long nx = P.at(j + 1).first;
    long long a = P.at(j).second;
    rem += a;
    long long l = nx - x - 1;
    long long s = l * (l + 1) / 2;
    if (rem < l + 1) {
      cout << -1 << endl;
      return 0;
    }
    ans += s;  // 1を埋める分
    rem -= (l + 1);
    ans += rem * (l + 1);  // 繰り上げ分
  }
  if (rem != 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
