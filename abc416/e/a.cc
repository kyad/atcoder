#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, const T b) { a = min(a, b); }

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
 * floyd(dist);
 * dp[i][j](dist[i][j])は、0からkまでを経由する時のiからjへの最短距離
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

/**
 * 最短距離を更新する計算において、経由する点がksに限られる時のFloyd-Warshall algorithm
 * https://atcoder.jp/contests/abc416/editorial/13536
 */
void floyd2(vector<vector<long long> > &dist, const vector<int> &ks) {
  int N = dist.size();
  for (int k: ks) {
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
  int N, M;
  cin >> N >> M;
  vector<vector<long long> > dist(N + 1, vector<long long>(N + 1, INF));  // N: 上空
  for (int i = 0; i <= N; i++) {
    dist.at(i).at(i) = 0;
  }
  for (int j = 0; j < M; j++) {
    int A, B;
    long long C;
    cin >> A >> B >> C;
    A--; B--;
    chmin(dist.at(A).at(B), C);
    chmin(dist.at(B).at(A), C);
  }
  int K;
  long long T;
  cin >> K >> T;
  for (int k = 0; k < K; k++) {
    int D;
    cin >> D;
    D--;
    dist.at(D).at(N) = T;
    dist.at(N).at(D) = 0;
  }
  floyd(dist);
  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      long long t;
      cin >> x >> y >> t;
      x--; y--;
      chmin(dist.at(x).at(y), t);
      chmin(dist.at(y).at(x), t);
      vector<int> ks;
      ks.push_back(x);
      ks.push_back(y);
      floyd2(dist, ks);
    } else if (type == 2) {
      int x;
      cin >> x;
      x--;
      dist.at(x).at(N) = T;
      dist.at(N).at(x) = 0;
      vector<int> ks;
      ks.push_back(x);
      ks.push_back(N);
      floyd2(dist, ks);
    } else {
      long long ans = 0;
      for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
          if (dist.at(u).at(v) == INF) {
            continue;
          }
          ans += dist.at(u).at(v);
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
