#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void f(long long x) {
  if (x > 0) {
    cout << '+' << endl;
  } else if (x < 0) {
    cout << '-' << endl;
  } else {
    cout << '0' << endl;
  }
}

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> P(N, 0);
  for (int n = 1; n < N; n++) {
    cin >> P.at(n);
    P.at(n)--;
  }
  vector<vector<int> > graph(N);
  for (int i = 1; i < N; i++) {
    graph[P.at(i)].push_back(i);
  }
  // depth[i]: 深さ
  vector<long long> depth(N, 0);
  // 木DP。計算量O(N)。graphは有向でも無向でも良い
  auto dfs_tree = [&](auto dfs_tree, int u, int parent) -> void {
    if (parent == -1) {
      depth[u] = 0;
    } else {
      depth[u] = depth[parent] + 1;
    }
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      dfs_tree(dfs_tree, v, u);
    }
  };
  const int root = 0;
  dfs_tree(dfs_tree, root, -1);

  const int M = *max_element(depth.begin(), depth.end());
  vector<long long> sum(M + 1, 0);
  for (int u = 0; u < N; u++) {
    sum.at(depth.at(u)) += A.at(u);
  }
  for (int d = M; d >= 0; d--) {
    if (sum.at(d) == 0) {
      continue;
    }
    f(sum.at(d));
    return 0;
  }
  cout << 0 << endl;
  return 0;
}
