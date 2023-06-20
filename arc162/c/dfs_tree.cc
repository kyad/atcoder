#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void testcase() {
  int N, K;
  cin >> N >> K;
  vector<vector<int> > graph(N);
  for (int v = 1; v < N; v++) {
    int P;
    cin >> P;
    P--;
    graph[P].push_back(v);
  }
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }

  bool ans = false;
  for (int root = 0; root < N; root++) {
    vector<int> child(N, -1);  // 自分以下のノード数 自分を含む
    vector<int> count(N, -1);  // 自分以下のノードで-1の数 自分を含む
    vector<int> countK(N, -1);  // 自分以下のノードでKの数 自分を含む
    set<int> st;
    auto dfs_tree = [&](auto dfs_tree, int u, int parent) -> void {
      // 最初に訪問した u
      child[u] = 1;
      count[u] = A[u] == -1 ? 1 : 0;
      countK[u] = A[u] == K ? 1 : 0;
      if (0 <= A[u] && A[u] < K) {
        st.insert(A[u]);
      }
      for (int v : graph.at(u)) {
        if (v == parent) {
          continue;
        }
        // 行きがけ u --> v
        dfs_tree(dfs_tree, v, u);
        // 帰りがけ u <-- v
        child[u] += child[v];
        count[u] += count[v];
        countK[u] += countK[v];
      }
    };
    dfs_tree(dfs_tree, root, -1);
    int f = st.size();
    if (f == K && count[root] <= 1 && countK[root] == 0) {
      ans = true;
    } else if (f == K - 1 && count[root] == 1 && countK[root] == 0) {
      ans = true;
    }
  }
  cout << (ans ? "Alice" : "Bob") << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
