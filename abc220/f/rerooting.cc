// https://atcoder.jp/contests/abc220/tasks/abc220_f

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > graph;
vector<long long> d, c;

void dfs0(int u, int parent) {
  d[u] = 0;
  c[u] = 1;
  for (int v : graph[u]) {
    if (v == parent) {
      continue;
    }
    dfs0(v, u);
    d[u] += c[v] + d[v];
    c[u] += c[v];
  }
}

vector<long long> ans;
void dfs1(int u, int parent) {
  ans[u] = 0;
  for (auto v : graph[u]) {
    ans[u] += (c[v] + d[v]);
  }
  int K = graph[u].size();
  vector<long long> left_d(K), right_d(K);
  vector<long long> left_c(K), right_c(K);
  for (int k = 0; k < K; k++) {
    left_d[k] = right_d[k] = d[graph[u][k]];
    left_c[k] = right_c[k] = c[graph[u][k]];
  }
  for (int k = 1; k < K; k++) {
    left_d[k] += left_d[k - 1];
    left_c[k] += left_c[k - 1];
  }
  for (int k = K - 2; k >= 0; k--) {
    right_d[k] += right_d[k + 1];
    right_c[k] += right_c[k + 1];
  }
  for (int k = 0; k < K; k++) {
    int v = graph[u][k];
    if (v == parent) {
      continue;
    }
    // Rerooting
    // Update dp[u]
    d[u] = 0;
    c[u] = 1;
    if (k >= 1) {
      d[u] += (left_c[k - 1] + left_d[k - 1]);
      c[u] += left_c[k - 1];
    }
    if (k <= K - 2) {
      d[u] += (right_c[k + 1] + right_d[k + 1]);
      c[u] += right_c[k + 1];
    }
    dfs1(v, u);
  }
}

int main() {
  int N;
  cin >> N;
  graph.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph[U].push_back(V);
    graph[V].push_back(U);
  }
  d.resize(N);
  c.resize(N);
  dfs0(0, -1);
  ans.resize(N);
  dfs1(0, -1);
  for (int i = 0; i < N; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
