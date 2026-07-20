#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long INF = 4e18;

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> W(N), T(N);
  for (int i = 0; i < N; i++) {
    cin >> W.at(i) >> T.at(i);
  }
  vector<long long> P(M);
  for (int j = 0; j < M; j++) {
    cin >> P.at(j);
  }
  vector<tuple<long long, int, int>> events(N + M);
  for (int i = 0; i < N; i++) {
    events.at(i) = make_tuple(W.at(i), 2, i);
  }
  for (int j = 0; j < M; j++) {
    events.at(N + j) = make_tuple(P.at(j), 1, j);
  }
  sort(events.begin(), events.end());
  reverse(events.begin(), events.end());
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > pq;  // 小さい要素がtop
  long long ans = -1;
  for (auto [x, type, k] : events) {
    if (type == 2) { // プリンタ
      int i = k;
      pq.push({T.at(i), i});  // 初回
    } else { // ジョブ
      int j = k;
      if (pq.empty()) {
        cout << -1 << endl;
        return 0;
      }
      auto [t, i] = pq.top();
      pq.pop();
      ans = max(ans, t);
      pq.push({t + T.at(i), i});  // 次の回
    }
  }

  cout << ans << '\n';
  return 0;
}
