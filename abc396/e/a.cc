#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> X(M), Y(M), Z(M);
  vector<vector<pair<int, int> > > graph(N);
  for (int j = 0; j < M; j++) {
    cin >> X.at(j) >> Y.at(j) >> Z.at(j);
    X.at(j)--; Y.at(j)--;
    graph.at(X.at(j)).push_back(make_pair(Y.at(j), Z.at(j)));
    graph.at(Y.at(j)).push_back(make_pair(X.at(j), Z.at(j)));
  }

  vector<int> A(N, 0);
  for (int bit = 0; bit < 30; bit++) {
    // 色を塗るdfs
    vector<int> color(N, -1);  // -1: 未探索、0: 白、1: 黒
    auto dfs0 = [&](auto dfs0, int u) -> void {
      for (auto [v, z] : graph.at(u)) {
        int nc;
        if ((z>>bit&1) == 0) {
          nc = color.at(u);
        } else {
          nc = 1 - color.at(u);
        }
        if (color.at(v) >= 0) {
          if (color.at(v) == nc) {
            continue;
          } else {  // 色が不整合の時
            cout << -1 << endl;
            exit(0);
          }
        }
        color.at(v) = nc;
        dfs0(dfs0, v);
      }
    };
    // dfs1の準備
    vector<bool> seen(N, false); // 探索完了フラグ
    for (int u = 0; u < N; u++) {
      if (color.at(u) >= 0) {
        continue;
      }
      // 色を塗る
      color.at(u) = 0;
      dfs0(dfs0, u);

      // それぞれの色を列挙するdfs
      vector<int> whites;
      vector<int> blacks;
      auto dfs1 = [&](auto dfs1, int u) -> void {
        seen.at(u) = true; // 訪問済(訪問完了)
        if (color.at(u) == 0) {
          whites.push_back(u);
        } else if (color.at(u) == 1) {
          blacks.push_back(u);
        } else {
          assert(false);
        }
        for (auto [v, z] : graph.at(u)) {
          if (seen.at(v)) {
            continue;
          }
          dfs1(dfs1, v);
        }
      };
      dfs1(dfs1, u);

      // 白の方が数が多いようにする
      if (blacks.size() > whites.size()) {
        for (int b : blacks) {
          color.at(b) = 0;
        }
        for (int w : whites) {
          color.at(w) = 1;
        }
      }
    }
    for (int u = 0; u < N; u++) {
      if (color.at(u) == 1) {
        A.at(u) |= (1 << bit);
      }
    }
  }
  dump(A);
  return 0;
}
