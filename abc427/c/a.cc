#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<bool> > graph(N, vector<bool>(N, false));
  for (int j = 0; j < M; j++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    graph.at(u).at(v) = true;
  }
  int N2 = 1<<N;
  const int INF = 1e9;
  int ans = INF;
  for (int bit = 0; bit < N2; bit++) {  // 0は白、1は黒
    int now = 0;
    // 白同士
    for (int u = 0; u < N; u++) {
      if ((bit>>u)&1) continue;
      for (int v = 0; v < N; v++) {
        if ((bit>>v)&1) continue;
        if (graph.at(u).at(v) == true) {
          now++;
        }
      }
    }
    // 黒同士
    for (int u = 0; u < N; u++) {
      if (! ((bit>>u)&1)) continue;
      for (int v = 0; v < N; v++) {
        if (! ((bit>>v)&1)) continue;
        if (graph.at(u).at(v) == true) {
          now++;
        }
      }
    }
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
