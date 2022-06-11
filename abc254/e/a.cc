// https://atcoder.jp/contests/abc254/tasks/abc254_e

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int> > graph(N);
  for (int m = 0; m < M; m++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  // dp[i][j]: iからちょうどj歩で行ける頂点の集合
  vector<vector<set<int> > > dp(N, vector<set<int> >(4));
  for (int i = 0; i < N; i++) {
    dp[i][0].insert(i);
  }
  for (int j = 0; j <= 2; j++) {
    for (int i = 0; i < N; i++) {
      set<int> &st = dp[i][j];
      for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        int u = *it;
        for (size_t k = 0; k < graph[u].size(); k++) {
          int v = graph[u][k];
          dp[i][j + 1].insert(v);
        }
      }
    }
  }
  // dp[i][j]: iからj歩以下で行ける頂点の集合
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 2; j++) {
      set<int> &st = dp[i][j];
      for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
        int u = *it;
        dp[i][j + 1].insert(u);
      }
    }
  }
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int x, k;
    cin >> x >> k;
    x--;
    int ans = 0;
    for (set<int>::iterator it = dp[x][k].begin(); it != dp[x][k].end(); it++) {
      ans += (*it + 1);
    }
    cout << ans << endl;
  }
  return 0;
}
