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
  vector<vector<long long> > dist(N, vector<long long>(N, INF));
  for (int n = 0; n < N; n++) {
    dist[n][n] = 0;
  }
  for (int m = 0; m < M; m++) {
    int U, V, W;
    cin >> U >> V >> W;
    U--; V--;
    dist[U][V] = W;
  }
  floyd(dist);

  int N2 = 1<<N;
  
  // dp[i][j]: 今までjを通った時のiにおける重みの総和の最小値
  vector<vector<long long> > dp(N, vector<long long>(N2, INF));
  for (int i = 0; i < N; i++) {
    dp[i][1<<i] = 0;
  }
  for (int j = 0; j < N2; j++) {
    for (int i = 0; i < N; i++) {
      if (!(j>>i&1)) {
        continue;
      }
      if (dp[i][j] == INF) {  // 負の重み対策
        continue;
      }
      for (int ni = 0; ni < N; ni++) {
        int nj = j | (1<<ni);
        if (dist[i][ni] == INF) {  // 負の重み対策
          continue;
        }
        dp[ni][nj] = min(dp[ni][nj], dp[i][j] + dist[i][ni]);
      }
    }
  }
  long long ans = INF;
  for (int i = 0; i < N; i++) {
    ans = min(ans, dp[i][N2 - 1]);
  }
  if (ans == INF) {
    cout << "No" << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
