#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

/**
 * Floyd-Warshall algorithm
 * 計算量 O(N^3)
 * distは以下のように初期化する。終了後にdist[i][j]にiからjへの距離の最小値が上書きされる。
 * distに負の重みがあっても負閉路がなければ利用可能。
 * vector<vector<long long> > dist(N, vector<long long>(N, INF));
 * for (int n = 0; n < N; n++) {
 *   dist[n][n] = 0;
 * }
 * for (int i = 0; i < N; i++) {
 *   for (int j = 0; j < N; j++) {
 *     dist[i][j] = iからjへの距離
 *   }
 * }
 */
const long long INF = 4e18;
void floyd(vector<vector<long long> > &dist) {
  int N = dist.size();
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dist[i][k] == INF || dist[k][j] == INF) {  // 負の重み対策
          continue;
        }
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<int> A(M), B(M);
  vector<long long> C(M);
  for (int j = 0; j < M; j++) {
    cin >> A.at(j) >> B.at(j) >> C.at(j);
    A.at(j)--;
    B.at(j)--;
  }
  vector<tuple<int, int, int> > qs(Q);
  set<int> remains;
  for (int j = 0; j < M; j++) {
    remains.insert(j);
  }
  for (int q = 0; q < Q; q++) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      cin >> i;
      i--;
      qs.at(q) = make_tuple(type, i, -1);
      remains.erase(i);
    } else {
      int x, y;
      cin >> x >> y;
      x--; y--;
      qs.at(q) = make_tuple(type, x, y);
    }
  }
  reverse(qs.begin(), qs.end());

  vector<vector<long long> > dist(N, vector<long long>(N, INF));
  for (int n = 0; n < N; n++) {
    dist[n][n] = 0;
  }
  for (int j : remains) {
    int a = A.at(j);
    int b = B.at(j);
    long long c = C.at(j);
    dist[a][b] = c;
    dist[b][a] = c;
  }
  floyd(dist);

  vector<long long> ans;
  for (auto [type, x, y] : qs) {  // 逆順
    if (type == 2) {
      long long now = dist[x][y];
      if (now == INF) {
        now = -1;
      }
      ans.push_back(now);
    } else {  // Floydの追加
      int a = A[x];
      int b = B[x];
      long long c = C[x];

      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          if (dist[i][a] != INF && dist[b][j] != INF) {  // 負の重み対策
            dist[i][j] = min(dist[i][j], dist[i][a] + c + dist[b][j]);
          }
          if (dist[i][b] != INF && dist[a][j] != INF) {  // 負の重み対策
            dist[i][j] = min(dist[i][j], dist[i][b] + c + dist[a][j]);
          }
        }
      }

    }
  }
  reverse(ans.begin(), ans.end());
  for (long long a : ans) {
    cout << a << endl;
  }
  return 0;
}
