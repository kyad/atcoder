// https://atcoder.jp/contests/abc227/tasks/abc227_f

#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<int> > A(H, vector<int>(W));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> A[y][x];
    }
  }
  // Dijkstra's algorithm for sparse graph (O|E|log|V|)
  const long long INF = 1000000000LL * (30 + 30) + 1;
  vector<vector<long long> > dist(H, vector<long long>(W, INF));
  dist[0][0] = A[0][0];
  priority_queue<pair<long long, pair<int, int> >,
                 vector<pair<long long, pair<int, int> > >,
                 greater<pair<long long, pair<int, int> > > > pq;
  pq.push(make_pair(A[0][0], make_pair(0, 0)));
  vector<vector<multiset<int> > > ms(H, vector<multiset<int> >(W));
  ms[0][0].insert(A[0][0]);
  while (!pq.empty()) {
    long long dist_min = pq.top().first;
    int y = pq.top().second.first;
    int x = pq.top().second.second;
    pq.pop();
    if (dist_min > dist[y][x]) {
      // garbage
      continue;
    }
    const int dy[2] = { 0, 1 };
    const int dx[2] = { 1, 0 };
    for (int k = 0; k < 2; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (ny >= H || nx >= W) {
        continue;
      }
      long long ndist = dist_min + A[ny][nx];
      if (ms[y][x].size() == K) {
        ndist -= min(A[ny][nx], *ms[y][x].begin());
      }
      if (dist[ny][nx] > ndist) {
        // 過去k個以上も含めて評価しないといけない。
        // 例えば、(1, 1, 10)より(1, 6, 6)が良いかもしれない。(test01参照)
        // なので、これが最小になるとは限らない。
        dist[ny][nx] = ndist;
        ms[ny][nx] = ms[y][x];
        ms[ny][nx].insert(A[ny][nx]);
        if (ms[ny][nx].size() == K + 1) {
          ms[ny][nx].erase(ms[ny][nx].begin());
        }
        pq.push(make_pair(ndist, make_pair(ny, nx)));
      }
    }
  }
  cout << dist[H - 1][W - 1] << endl;
  return 0;
}
