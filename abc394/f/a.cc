#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > graph(N);
  for (int m = 0; m < N - 1; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    graph.at(U).push_back(V);
    graph.at(V).push_back(U);
  }

  auto solve = [&](int root) {
    vector<int> dp(N, 0);
    auto dfs = [&](auto dfs, int u, int parent) -> void {
      multiset<int, greater<int> > st;
      for (int v: graph.at(u)) {
        if (v == parent) {
          continue;
        }
        dfs(dfs, v, u);
        st.insert(dp.at(v));
      }
      if (parent == -1) {
        if (st.size() >= 4) { 
          auto it = st.begin();
          int ans = *it;
          it++; ans += *it;
          it++; ans += *it;
          it++; ans += *it;
          ans++;  // 自分
          dp.at(u) = ans;
        }
      } else {
        if (st.size() >= 3) { 
          auto it = st.begin();
          int ans = *it;
          it++; ans += *it;
          it++; ans += *it;
          ans++;  // 自分
          dp.at(u) = ans;
        }
      }
    };

    dfs(dfs, root, -1);

    int n = 0;
    for (int i = 0; i < N; i++) {
      n = max(n, dp.at(i));
    }

    int ans;
    if (n >= 1) {
      ans = 3 * n + 2;
    } else {
      ans = -1;
    }

    return ans;
  };

  int ans = -1;
  const int M = 11;
  for (int i = 0; i < M; i++) {
    if (i >= N) {
      continue;
    }
    int now = solve(i);
    ans = max(ans, now);
  }

  cout << ans << endl;
  return 0;
}
