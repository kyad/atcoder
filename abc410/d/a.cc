#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int K = 10;
  int K2 = 1<<K;
  vector<vector<pair<int, int> > > graph(N);
  for (int m = 0; m < M; m++) {
    int U, V, W;
    cin >> U >> V >> W;
    U--; V--;
    graph.at(U).push_back(make_pair(V, W));
  }
  vector<vector<bool> > visited(N, vector<bool>(K2, false));  // visited[u][b]: (ノード番号u、重みのxor b)に訪問済みか
  queue<pair<int, int> > q;  // (ノード番号、重みのxor)
  visited.at(0).at(0) = true;
  q.push(make_pair(0, 0));
  while (!q.empty()) {
    auto [u, value] = q.front();
    q.pop();
    for (auto [v, weight]: graph.at(u)) {
      int nvalue = value ^ weight;
      if (visited.at(v).at(nvalue)) {
        continue;
      }
      visited.at(v).at(nvalue) = true;
      q.push(make_pair(v, nvalue));
    }
  }
  const int INF = 1e9;
  int ans = INF;
  for (int b = 0; b < K2; b++) {
    if (visited.at(N - 1).at(b) == true) {
      ans = min(ans, b);
    }
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
