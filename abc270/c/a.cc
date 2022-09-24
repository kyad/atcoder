#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  X--; Y--;
  vector<vector<int> > graph(N);
  for (int n = 0; n < N - 1; n++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.at(U).push_back(V);
    graph.at(V).push_back(U);
  }
  vector<int> ans;
  auto dfs = [&](auto dfs, int u, int parent) -> bool {
    bool ret = false;
    if (u == Y) {
      ret = true;
    }
    for (auto v : graph[u]) {
      if (v == parent) {
        continue;
      }
      if (dfs(dfs, v, u)) {
        ret = true;
      }
    }
    if (ret) {
      ans.push_back(u);
    }
    return ret;
  };
  dfs(dfs, X, -1);
  reverse(ans.begin(), ans.end());
  for (size_t i = 0; i < ans.size(); i++) {
    cout << (ans.at(i) + 1);
    if (i + 1 == ans.size()) {
      cout << '\n';
    } else {
      cout << ' ';
    }
  }
  return 0;
}
