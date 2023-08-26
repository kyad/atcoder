#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<long long> > graph(N, vector<long long>(N, -1));
  for (int m = 0; m < M; m++) {
    int A, B;
    long long C;
    cin >> A >> B >> C;
    A--; B--;
    graph[A][B] = C;
    graph[B][A] = C;
  }
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    P[n] = n;
  }
  
  auto solve = [&](const vector<int> &P) {
    long long ans = 0;
    int u = P[0];
    for (int n = 1; n < N; n++) {
      int v = P[n];
      if (graph[u][v] >= 0) {
        ans += graph[u][v];
        u = v;
      } else {
        break;
      }
    }
    return ans;
  };

  long long ans = 0;
  do {
    long long now = solve(P);
    ans = max(ans, now);
  } while (next_permutation(P.begin(), P.end()));
  cout << ans << endl;
  return 0;
}
