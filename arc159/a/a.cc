#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<vector<int> > A(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A.at(i).at(j);
    }
  }
  vector<vector<int> > graph(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (A[i][j] == 1) {
        graph[i].push_back(j);
      }
    }
  }
  
  const int INF = 1e9;
  vector<vector<int> > dist(N, vector<int>(N, INF));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (A[i][j] == 1) {
        dist[i][j] = 1;
      }
    }
  }
  for (int n = 0; n < N; n++) {
    dist[n][n] = 0;
  }

  // Floyd-Warshall algorithm
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    long long S, T;
    cin >> S >> T;
    S--; T--;
    int s = (int)(S % (long long)N);
    int t = (int)(T % (long long)N);
    int ans = INF;
    long long gs = S / (long long)(N);
    long long gt = T / (long long)(N);
    if (gs == gt) {  // same group
      ans = dist[s][t];
    } else {  // different group
      for (int u = 0; u < N; u++) {
        if (dist[s][u] == INF) {
          continue;
        }
        if (A[u][t] == 0) {
          continue;
        }
        int now = dist[s][u] + 1;
        ans = min(ans, now);
      }
    }
    if (ans == INF) {
      ans = -1;
    }
    cout << ans << '\n';
  }
  return 0;
}
