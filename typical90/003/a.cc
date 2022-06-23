// https://atcoder.jp/contests/typical90/tasks/typical90_c

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  for (int n = 0; n < N - 1; n++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  // dp[0][u]: uを根とした木の深さの最大値
  // dp[1][u]: uを根とした木で、複数の子を持つノードを通るスコアの最大値
  vector<vector<int> > dp(2, vector<int>(N, 0));
  auto dfs = [&](auto dfs, int u, int parent) -> void {
    multiset<int> st;
    dp[0][u] = 1;
    for (size_t i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      if (v == parent) {
        continue;
      }
      dfs(dfs, v, u);
      dp[0][u] = max(dp[0][u], dp[0][v] + 1);
      dp[1][u] = max(dp[1][u], dp[1][v]);
      st.insert(dp[0][v]);
    }
    if (st.size() >= 2) {
      int now = 1;
      multiset<int>::reverse_iterator it = st.rbegin();
      for (int i = 0; i < 2; i++) {
        now += *it;
        it++;
      }
      dp[1][u] = max(dp[1][u], now);
    }
  };
  dfs(dfs, 0, -1);
  int ans = max(dp[0][0], dp[1][0]);
  cout << ans << endl;
  return 0;
}
