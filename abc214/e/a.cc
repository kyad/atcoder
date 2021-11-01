// https://atcoder.jp/contests/abc214/tasks/abc214_e

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void testcase() {
  int N;
  cin >> N;
  vector<int> L(N);
  vector<pair<int, int> > LR(N);
  for (int n = 0; n < N; n++) {
    int l, r;
    cin >> l >> r;
    L.at(n) = l;
    LR.at(n) = make_pair(l, r);
  }
  sort(L.begin(), L.end());
  sort(LR.begin(), LR.end());
  int L_idx = L[0];
  int idx = 0;
  priority_queue<int, vector<int>, greater<int> > pq;
  bool ans;
  while (true) {
    while (L_idx == LR[idx].first) {
      pq.push(LR[idx].second);
      idx++;
      if (idx >= LR.size()) {
        break;
      }
    }
    if (pq.empty()) {
      ans = false;
      break;
    }
    if (pq.top() < L_idx) {
      ans = false;
      break;
    }
    pq.pop();
    if (pq.empty()) {
      vector<int>::iterator it = lower_bound(L.begin(), L.end(), L_idx + 1);
      if (it == L.end()) {
        ans = true;
        break;
      }
      L_idx = *it;
    } else {
      L_idx++;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
