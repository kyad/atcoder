// https://atcoder.jp/contests/abc074/tasks/arc083_b

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > A(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  // Floyd-Warshall
  vector<vector<int> > dist(A);
  vector<vector<int> > mask(N, vector<int>(N, 1));
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      if (k == i) {
        continue;
      }
      for (int j = 0; j < N; j++) {
        if (k == j || i == j) {
          continue;
        }
        int temp = dist[i][k] + dist[k][j];
        if (temp <= dist[i][j]) {
          mask[i][j] = 0;
          dist[i][j] = temp;
        }
      }
    }
  }
  long long ans = 0;
  for (int u = 0; u < N; u++) {
    for (int v = u + 1; v < N; v++) {
      if (A[u][v] > dist[u][v]) {
        cout << -1 << endl;
        return 0;
      }
      ans += A[u][v] * mask[u][v];
    }
  }
  cout << ans << endl;
  return 0;
}
