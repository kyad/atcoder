#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> X(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> X.at(i);
  }
  const long long INF = 4e18;
  vector<long long> L(N + 1, -INF);
  vector<long long> R(N + 1, INF);
  vector<long long> D(N + 1, -1);
  set<pair<long long, int> > P, Q;
  long long sum = 0;
  // 初期値
  X.at(0) = 0;
  D.at(0) = 0;
  P.insert(make_pair(X.at(0), 0));
  Q.insert(make_pair(-X.at(0), 0));
  // 番兵
  P.insert(make_pair(-INF, -1));
  P.insert(make_pair(INF, -1));
  Q.insert(make_pair(-INF, -1));
  Q.insert(make_pair(INF, -1));
  for (int j = 1; j <= N; j++) {
    {
      // 左を探す
      auto it = Q.lower_bound(make_pair(-X.at(j), j));
      int i = it->second;
      if (i >= 0) {
        R.at(i) = X.at(j);
        long long nd = min(X.at(i) - L.at(i), R.at(i) - X.at(i));
        long long diff = nd - D.at(i);
        sum += diff;
        D.at(i) = nd;
        L.at(j) = X.at(i);
      }
    }
    {
      // 右を探す
      auto it = P.lower_bound(make_pair(X.at(j), j));
      int i = it->second;
      if (i >= 0) {
        L.at(i) = X.at(j);
        long long nd = min(X.at(i) - L.at(i), R.at(i) - X.at(i));
        long long diff = nd - D.at(i);
        sum += diff;
        D.at(i) = nd;
        R.at(j) = X.at(i);
      }
    }
    // jの追加
    D.at(j) = min(X.at(j) - L.at(j), R.at(j) - X.at(j));
    sum += D.at(j);
    P.insert(make_pair(X.at(j), j));
    Q.insert(make_pair(-X.at(j), j));
    cout << sum << '\n';
  }
  return 0;
}
