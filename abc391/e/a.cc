#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int majority(int a, int b, int c) {
  vector<int> count(2);
  count.at(a)++;
  count.at(b)++;
  count.at(c)++;
  if (count.at(0) > count.at(1)) {
    return 0;
  } else if (count.at(0) < count.at(1)) {
    return 1;
  } else {
    exit(1);
  }
}

const int INF = 1e9;

// m^n, O(log n)
long long power(long long m, long long n, int mod = INF) {
  long long a = m % mod;
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  string A;
  cin >> A;
  vector<vector<int> > graph;
  vector<int> B;
  int N3 = power(3, N);
  // グラフ構築 最下段
  for (int i = 0; i < N3; i++) {
    graph.push_back(vector<int>());
    B.push_back(A.at(i) - '0');
  }
  // グラフ構築
  auto connect = [&](int u, int v) {
    graph.at(u).push_back(v);
    graph.at(v).push_back(u);
  };
  int i = 0;
  while ((int)graph.size() != i + 1) {
    int u = graph.size();  // 次の番号
    graph.push_back(vector<int>());  // graph[u]
    connect(i, u);
    connect(i + 1, u);
    connect(i + 2, u);
    int nb = majority(B.at(i), B.at(i + 1), B.at(i + 2));
    B.push_back(nb);  // B[u]
    i += 3;
  }
  int K = graph.size();  // ノード数
  int root = i;  // ここでiはroot

  // DFS
  vector<int> dp(K, 0);  // dp[u]: uより下を変える個数の最小値
  // 木DP。計算量O(N)。graphは有向でも無向でも良い
  auto dfs_tree = [&](auto dfs_tree, int u, int parent) -> int {
    if ((int)graph[u].size() == 1) {
      return 1;  // 末端の時
    }
    vector<int> costs;
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      if (B.at(u) != B.at(v)) {  // 違う値の時
        continue;
      }
      costs.push_back(dfs_tree(dfs_tree, v, u));
    }
    sort(costs.begin(), costs.end());
    int K = costs.size();
    int ans;
    if (K == 2) {
      ans = costs.at(0);
    } else if (K == 3) {
      ans = costs.at(0) + costs.at(1);
    } else {
      assert(false);
    }
    return ans;
  };
  int ans = dfs_tree(dfs_tree, root, -1);
  cout << ans << endl;
  return 0;
}
