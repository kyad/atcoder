#include <bits/stdc++.h>
using namespace std;

int main() {
  int L, Q;
  cin >> L >> Q;
  priority_queue<int, vector<int>, greater<int> > pq;
  vector<int> pr;
  vector<pair<int, int> > cx;
  for (int q = 0; q < Q; q++) {
    int c, x;
    cin >> c >> x;
    if (c == 1) {
      pq.push(x);
    }
    cx.push_back(make_pair(c, x));
  }
  pq.push(L);
  map<int, pair<int, int> > m;
  vector<int> cut;
  while (!pq.empty()) {
    cut.push_back(pq.top());
    pq.pop();
  }
  int left = 0;
  for (size_t i = 0; i < cut.size(); i++) {
    int right = cut[i];
    int len = right - left;
    int next = (i != cut.size() - 1 ? cut[i + 1] : -1);
    m[right] = make_pair(len, next);
    left = right;
  }
  vector<int> ans;
  for (int q = Q - 1; q >= 0; q--) {
    int c = cx[q].first;
    int x = cx[q].second;
    if (c == 2) {
      auto it_right = m.lower_bound(x);
      int right_len = it_right->second.first;
      ans.push_back(right_len);
    } else if (c == 1) {
      int right_len = m[x].first;
      int next = m[x].second;
      auto it_next = m.lower_bound(next);
      int next_len = it_next->second.first;
      m.erase(x);
      it_next->second.first = right_len + next_len;
    }
  }
  reverse(ans.begin(), ans.end());
  for (size_t i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
