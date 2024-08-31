#include <algorithm>
#include <cassert>
#include <iostream>
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
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  vector<vector<long long> > dist(N, vector<long long>(N, INF));
  for (int n = 0; n < N; n++) {
    dist[n][n] = 0;
  }

  vector<int> U(M);
  vector<int> V(M);
  vector<long long> T(M);
  for (int m = 0; m < M; m++) {
    cin >> U.at(m) >> V.at(m) >> T.at(m);
    U.at(m)--; V.at(m)--;
    dist[U.at(m)][V.at(m)] = min(dist[U.at(m)][V.at(m)], T.at(m));
    dist[V.at(m)][U.at(m)] = min(dist[V.at(m)][U.at(m)], T.at(m));
  }
  // dist[u][v]: uからvの最短時間
  floyd(dist);

  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int K;
    cin >> K;
    vector<int> B(K);  // 橋の番号
    for (int k = 0; k < K; k++) {
      cin >> B.at(k);
      B.at(k)--;
    }

    // 橋の入出力でビット全探索
    int K2 = 1<<K;
    long long ans = INF;
    for (int bit = 0; bit < K2; bit++) {
      // 橋を渡る順序で順列全探索
      vector<int> P(K, -1);
      for (int i = 0; i < K; i++) {
        P.at(i) = i;
      }
      do {  // ケース
        long long now = 0; // このルートの移動時間
        vector<int> ss;  // 計算用
        vector<int> ts;  // 計算用
        ss.push_back(0);
        for (int i = 0; i < K; i++) {  // i番目に渡る橋がm
          int p = P.at(i);  // 順列
          int m = B.at(p);  // m: 橋の番号
          int u = U.at(m);  // 開始
          int v = V.at(m);  // 終点
          if (bit>>i&1) {
            swap(u, v);
          }
          ts.push_back(u);
          ss.push_back(v);
          now += T.at(m);
        }
        ts.push_back(N - 1);
        assert((int)ss.size() == K + 1);
        assert((int)ts.size() == K + 1);
        for (int i = 0; i < K + 1; i++) {
          now += dist[ss.at(i)][ts.at(i)];
        }
        ans = min(ans, now);
      } while (next_permutation(P.begin(), P.end()));
    }
    cout << ans << '\n';
  }
  return 0;
}
