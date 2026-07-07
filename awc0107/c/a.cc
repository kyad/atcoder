#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  map<int, vector<pair<string, int>>> mp;
  vector<string> S(N);
  vector<int> V(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i) >> V.at(i);
    mp[V.at(i)].push_back(make_pair(S.at(i), i));
  }
  map<int, string> memo;
  for (int qi = 0; qi < Q; qi++) {
    int X;
    cin >> X;
    if (mp.contains(X)) {
      vector<string> ans;
      for (auto [name, i] : mp[X]) {
        ans.push_back(name);
      }
      dump(ans);
    } else {
      if (memo.contains(X)) {
        cout << memo[X] << '\n';
        continue;
      }
      vector<pair<string, int>> cand;
      auto upper = mp.upper_bound(X);
      auto lower = mp.lower_bound(X);
      if (N == 1) {
        cand.push_back(make_pair(S.at(0), 0));
      } else if (upper == mp.end()) {
        for (auto [name, i] : prev(lower)->second) {
          cand.push_back(make_pair(name, i));
        }
      } else if (lower == mp.begin()) {
        for (auto [name, i] : upper->second) {
          cand.push_back(make_pair(name, i));
        }
      } else {
        int u = upper->first - X;
        int l = X - prev(lower)->first;
        if (u <= l) {
          for (auto [name, i] : upper->second) {
            cand.push_back(make_pair(name, i));
          }
        }
        if (l <= u) {
          for (auto [name, i] : prev(lower)->second) {
            cand.push_back(make_pair(name, i));
          }
        }
      }
      string ans;
      const int INF = 1e9;
      int mn = INF;
      for (auto [name, i] : cand) {
        if (i < mn) {
          ans = name;
          mn = i;
        }
      }
      memo[X] = ans;
      cout << ans << '\n';
    }
  }
  return 0;
}
