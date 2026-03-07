#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<vector<int> > graph(N);
  for (int i = 0; i < N - 1; i++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.at(U).push_back(V);
    graph.at(V).push_back(U);
  }
  
  multiset<int> ms;
  vector<bool> dp(N, false);
  auto dfs = [&](auto dfs, int u, int parent) -> void {
    if (parent >= 0 && dp.at(parent) == true) {
      dp.at(u) = true;
    }
    if (ms.contains(A.at(u))) {
      dp.at(u) = true;
    }
    ms.insert(A.at(u));
    for (int v : graph.at(u)) {
      if (v == parent) {
        continue;
      }
      dfs(dfs, v, u);
    }
    ms.erase(ms.find(A.at(u)));
  };
  dfs(dfs, 0, -1);
  for (int u = 0; u < N; u++) {
    cout << (dp.at(u) ? "Yes" : "No") << '\n';
  }
  return 0;
}
