#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  vector<int> oks;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    if (A == 0 && B == 0) {
      oks.push_back(i);
    } else {
      A--; B--;
      graph.at(A).push_back(i);
      graph.at(B).push_back(i);
    }
  }
  vector<bool> seen(N, false);  // 探索完了フラグ
  auto dfs = [&](auto dfs, int u) -> void {
    seen.at(u) = true;  // 訪問済(訪問完了)
    // if () {
    //   return;
    // }
    for (int v : graph.at(u)) {
      if (seen.at(v)) {
        continue;
      }
      dfs(dfs, v);
    }
  };
  for (int i : oks) {
    dfs(dfs, i);
  }
  int ans = count(seen.begin(), seen.end(), true);
  cout << ans << endl;
  return 0;
}
