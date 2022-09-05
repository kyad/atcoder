// https://atcoder.jp/contests/abc267/tasks/abc267_f

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  for (int n = 0; n < N - 1; n++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }

  // Diameter
  auto dfs_farthest = [&](auto dfs_farthest, int u, int d = 0, int parent = -1) -> pair<int, int> {
    pair<int, int> ans = make_pair(d, u);
    for (int v : graph[u]) {
      if (v == parent) {
        continue;
      }
      ans = max(ans, dfs_farthest(dfs_farthest, v, d + 1, u));
    }
    return ans;
  };
  int a = dfs_farthest(dfs_farthest, 0).second;
  int b = dfs_farthest(dfs_farthest, a).second;

  // Level Ancestor Probrem
  // ダブリングテーブルda[m][u]: aを根として見た時、uから2^m回上に移動した時のノード番号
  const int D = 18;  // log_2(2*10^5) = 17.6...
  vector<vector<int> > da(D, vector<int>(N));
  vector<vector<int> > db(D, vector<int>(N));

  auto dfs = [&](auto dfs, int u, int parent, int root) -> void {
    if (root == a) {
      da[0][u] = parent;
    } else {
      db[0][u] = parent;
    }
    for (int v : graph[u]) {
      if (v == parent) {
        continue;
      }
      dfs(dfs, v, u, root);
    }
  };
  dfs(dfs, a, -1, a);
  dfs(dfs, b, -1, b);

  for (int m = 0; m < D - 1; m++) {
    for (int u = 0; u < N; u++) {
      da[m + 1][u] = (da[m][u] == -1 ? -1 : da[m][da[m][u]]);
      db[m + 1][u] = (db[m][u] == -1 ? -1 : db[m][db[m][u]]);
    }
  }

  // uからa方向にk歩進んだノードを返す
  auto up_a = [&](int u, int k) {
    for (int m = D - 1; m >= 0; m--) {
      if ((k>>m)&1) {
        u = da[m][u];
        if (u < 0) {
          return u;
        }
      }
    }
    return u;
  };
  auto up_b = [&](int u, int k) {
    for (int m = D - 1; m >= 0; m--) {
      if ((k>>m)&1) {
        u = db[m][u];
        if (u < 0) {
          return u;
        }
      }
    }
    return u;
  };

  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int U, K;
    cin >> U >> K;
    U--;
    int ans1 = up_a(U, K);
    if (ans1 >= 0) {
      ans1++;
    }
    int ans2 = up_b(U, K);
    if (ans2 >= 0) {
      ans2++;
    }
    int ans = max(ans1, ans2);
    cout << ans << '\n';
  }
  return 0;
}
