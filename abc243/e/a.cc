#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  const long long INF = 1e18;
  int N, M;
  cin >> N >> M;
  vector<vector<long long> > dist(N, vector<long long>(N, INF));
  for (int n = 0; n < N; n++) {
    dist[n][n] = 0;
  }
  vector<int> A(M), B(M), C(M);
  vector<int> needed(M, true);
  map<pair<int, int>, int> mp;
  for (int m = 0; m < M; m++) {
    int a, b, c;
    cin >> a >> b >> c;
    dist[a - 1][b - 1] = c;
    dist[b - 1][a - 1] = c;
    A.at(m) = a - 1;
    B.at(m) = b - 1;
    C.at(m) = c;
    mp[make_pair(a - 1, b - 1)] = m;
  }
  // Floyd-Warshall algorithm
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i != j && i != k && j != k) {
          if (dist[i][j] == dist[i][k] + dist[k][j]) {
            if (mp.count(make_pair(i, j)) > 0) {
              needed[mp[make_pair(i, j)]] = false;
            } else if (mp.count(make_pair(j, i)) > 0) {
              needed[mp[make_pair(j, i)]] = false;
            }
          }
        }
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  long long ans = 0;
  for (int m = 0; m < M; m++) {
    if ((dist[A[m]][B[m]] != C[m]) || (needed[m] == false)) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
