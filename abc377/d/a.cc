#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> L(N), R(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i) >> R.at(i);
    L.at(i)--; R.at(i)--;
  }
  multiset<pair<int, int> > ls, rs;
  for (int i = 0; i < N; i++) {
    ls.insert(make_pair(L.at(i), i));
    rs.insert(make_pair(R.at(i), i));
  }
  long long ans = (long long)(M + 1) * M / 2;
  for (int l = 0; l <= M - 1; l++) {
    // 完全に含むものを数える
    auto it = rs.lower_bound(make_pair(l, -1));
    if (it != rs.end()) {
      int rr = it->first;
      int contains = M - rr;
      ans -= contains;
    }
    while (!ls.empty()) {
      int top_L = ls.begin()->first;
      int top_i = ls.begin()->second;
      if (top_L <= l) {
        ls.erase(ls.begin());
      } else {
        break;
      }
      int top_R = R.at(top_i);
      rs.erase(make_pair(top_R, top_i));
    }
  }
  cout << ans << endl;
  return 0;
}
