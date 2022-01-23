// https://atcoder.jp/contests/abc208/tasks/abc208_d

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  const int INF = 1000000 * 400 + 1;
  vector<vector<int> > dist(N, vector<int>(N, INF));
  for (int n = 0; n < N; n++) {
    dist[n][n] = 0;
  }
  for (int m = 0; m < M; m++) {
    int A, B;
    int C;
    cin >> A >> B >> C;
    A--;
    B--;
    dist[A][B] = C;
  }
  long long ans = 0;
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        if (dist[i][j] != INF) {
          ans += dist[i][j];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
