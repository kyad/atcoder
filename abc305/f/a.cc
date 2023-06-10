#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<bool> seen(N, false);  // 探索完了フラグ
  auto dfs = [&](auto dfs, int u, int parent) -> void {
    seen.at(u) = true;  // 訪問済(訪問完了)
    if (u != 0) {
      cout << u + 1 << endl;
      if (u == N - 1) {
        string ok;
        cin >> ok;
        assert(ok == "OK");
        exit(0);
      }
    }
    int K;
    cin >> K;
    vector<int> vs(K);
    for (int k = 0; k < K; k++) {
      cin >> vs.at(k);
      vs.at(k)--;
    }
    for (int v : vs) {
      if (seen.at(v)) {
        continue;
      }
      dfs(dfs, v, u);
    }
    cout << parent + 1 << endl;
    int K2;
    cin >> K2;
    for (int k = 0; k < K2; k++) {
      int v;
      cin >> v;
      (void)v;
    }
  };
  dfs(dfs, 0, -1);
  return 0;
}
