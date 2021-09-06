// https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g
// https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361#11-bit-dp

#include <iostream>
#include <vector>
using namespace std;

int main() {
  const long long INF = 1000000000000 * 16 + 1;
  int N, M;
  cin >> N >> M;
  vector<vector<long long> > dist(N, vector<long long>(N, INF));
  vector<vector<long long> > time(N, vector<long long>(N, INF));
  for (int m = 0; m < M; m++) {
    int s, t;
    long long d, ti;
    cin >> s >> t >> d >> ti;
    dist[s - 1][t - 1] = d;
    dist[t - 1][s - 1] = d;
    time[s - 1][t - 1] = ti;
    time[t - 1][s - 1] = ti;
  }
  // Bit DP
  vector<vector<long long> > dp_dist(1 << N, vector<long long>(N, INF));
  vector<vector<long long> > dp_count(1 << N, vector<long long>(N, 0));
  dp_dist[1][0] = 0;
  dp_count[1][0] = 1;
  for (int S = 1; S < (1 << N); S++) {
    for (int v = 0; v < N; v++) {
      if (!(S >> v & 1)) {
        continue;
      }
      int Sv = S ^ (1 << v);  // S \ {v}
      for (int u = 0; u < N; u++) {
        if (!(Sv >> u & 1)) {
          continue;
        }
        long long temp = dp_dist[Sv][u] + dist[u][v];
        if (temp > time[u][v]) {
          continue;
        }
        if (temp < dp_dist[S][v]) {
          dp_dist[S][v] = temp;
          dp_count[S][v] = dp_count[Sv][u];
        } else if (temp == dp_dist[S][v]) {
          dp_count[S][v] += dp_count[Sv][u];
        }
      }
    }
  }
  long long ans_dist = INF;
  long long ans_count = 0;
  for (int u = 0; u < N; u++) {
    long long temp = dp_dist[(1 << N) - 1][u] + dist[u][0];
    if (temp > time[u][0]) {
      continue;
    }
    if (temp < ans_dist) {
      ans_dist = temp;
      ans_count = dp_count[(1 << N) - 1][u];
    } else if (temp == ans_dist) {
      ans_count += dp_count[(1 << N) - 1][u];
    }
  }
  if (ans_dist == INF) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << ans_dist << ' ' << ans_count << endl;
  }
  return 0;
}
