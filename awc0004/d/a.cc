// https://atcoder.jp/contests/awc0004/editorial/15793

#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int> > LR(M);
  for (int j = 0; j < M; j++) {
    int L, R;
    cin >> L >> R;
    LR.at(j) = make_pair(L, R);
  }
  sort(LR.begin(), LR.end());
  priority_queue<int, vector<int>, greater<int> > pq;  // 小さい要素がtop
  int j = 0;
  for (int i = 1; i <= N; i++) {
    while (j < M) {
      auto [L, R] = LR.at(j);
      if (L == i) {
        pq.push(R);
        j++;
      } else {
        break;
      }
    }
    if (!pq.empty()) {
      int R = pq.top();
      if (i > R) {
        cout << "No" << endl;
        return 0;
      } else {
        pq.pop();
      }
    }
  }
  if (!pq.empty()) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
