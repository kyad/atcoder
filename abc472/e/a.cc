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
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N, M;
    cin >> N >> M;
    vector<vector<int> > graph(N);
    for (int j = 0; j < M; j++) {
      int U, V;
      cin >> U >> V;
      U--; V--;
      graph.at(U).push_back(V);
      graph.at(V).push_back(U);
    }
    vector<vector<int> > graph2(graph);
    for (int u = 0; u < N; u++) {
      reverse(graph2.at(u).begin(), graph2.at(u).end());
    }
    // 2色
    vector<int> color(N, -1);
    //vector<bool> seen(N, false);  // 探索完了フラグ
    auto dfs = [&](auto dfs, int u, int nc) -> void {
      //seen.at(u) = true;  // 訪問済(訪問完了)
      color.at(u) = nc;
      for (int v : graph.at(u)) {
        //if (seen.at(v)) {
        if (color.at(v) >= 0) {
          continue;
        }
        dfs(dfs, v, 1 - nc);
      }
    };
    for (int u = 0; u < N; u++) {
      if (color.at(u) == -1) {
        dfs(dfs, u, 0);
      }
    }
    // 隣接するノードで同じ色があるか確認
    int a = -1, b = -1;
    bool ok = false;
    for (int u = 0; u < N; u++) {
      assert(color.at(u) >= 0);
      for (int v: graph.at(u)) {
        if (color.at(u) == color.at(v)) {
          a = u;
          b = v;

          // a->bの経路を探す
          vector<bool> seen(N, false);  // 探索完了フラグ
          vector<int> ans;
          auto dfs2 = [&](auto dfs2, int u) -> bool {
            bool found = false;
            seen.at(u) = true;  // 訪問済(訪問完了)
            if (u == b) {
              found = true;
            } else {
              for (int v : graph.at(u)) {
                if (u == a && v == b) {  // 直接a->bは禁止
                  continue;
                }
                if (u == b && v == a) {  // 直接a->bは禁止
                  continue;
                }
                if (seen.at(v)) {
                  continue;
                }
                bool now = dfs2(dfs2, v);
                if (now) {
                  found = true;
                }
              }
            }
            if (found) {
              ans.push_back(u + 1);
            }
            return found;
          };
          dfs2(dfs2, a);

          if (ans.size() >= 3 && ans.size() % 2 == 1) {
            cout << ans.size() << '\n';
            dump(ans);
            ok = true;
            break;
          }

          {
            // a->bの経路を探す graph2を使う
            vector<bool> seen(N, false);  // 探索完了フラグ
            vector<int> ans;
            auto dfs3 = [&](auto dfs3, int u) -> bool {
              bool found = false;
              seen.at(u) = true;  // 訪問済(訪問完了)
              if (u == b) {
                found = true;
              } else {
                for (int v : graph2.at(u)) {
                  if (u == a && v == b) {  // 直接a->bは禁止
                    continue;
                  }
                  if (u == b && v == a) {  // 直接a->bは禁止
                    continue;
                  }
                  if (seen.at(v)) {
                    continue;
                  }
                  bool now = dfs3(dfs3, v);
                  if (now) {
                    found = true;
                  }
                }
              }
              if (found) {
                ans.push_back(u + 1);
              }
              return found;
            };
            dfs3(dfs3, a);
            if (ans.size() >= 3 && ans.size() % 2 == 1) {
              cout << ans.size() << '\n';
              dump(ans);
              ok = true;
              break;
            }
          }

        }
      }
      if (ok) {
        break;
      }
    }
    if (!ok) {
      cout << "-1" << '\n';
      continue;
    }
  }
  return 0;
}
