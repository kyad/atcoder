#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0, int end = -1) {
  if (end < 0) {
    end = x.size();
  }
  for (int i = start; i < end; i++) {
    cout << x.at(i) << (i + 1 == end ? '\n' : ' ');
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> ans(N + 1, 0);
  vector<vector<pair<int, int>>> LRs(Q);
  for (int qi = 0; qi < Q; qi++) {
    int L, R, X;
    cin >> L >> R >> X;
    L--; R--; X--;
    LRs.at(X).push_back(make_pair(L, R));
  }
  for (int x = 0; x < Q; x++) {
    if (LRs.at(x).empty()) {
      continue;
    }
    sort(LRs.at(x).begin(), LRs.at(x).end());
    vector<pair<int, int>> combine;
    int l = LRs.at(x).at(0).first, r = LRs.at(x).at(0).second;
    for (size_t i = 1; i < LRs.at(x).size(); i++) {
      int L = LRs.at(x).at(i).first;
      int R = LRs.at(x).at(i).second;
      if (L <= r + 1) {
        r = max(r, R);
      } else {
        combine.push_back(make_pair(l, r));
        l = L, r = R;
      }
    }
    combine.push_back(make_pair(l, r));
    for (auto [l, r] : combine) {
      ans.at(l)++;
      ans.at(r + 1)--;
    }
  }
  for (int i = 0; i < N; i++) {
    ans.at(i + 1) += ans.at(i);
  }
  dump(ans, 0, N);
  return 0;
}
