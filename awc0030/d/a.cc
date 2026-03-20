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
  int N;
  cin >> N;
  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T.at(i);
    T.at(i)--;
  }
  vector<int> v(N, -1);
  vector<int> loop(N, -1);
  vector<bool> visited(N, false);
  auto dfs = [&](auto dfs, int u) -> void {
    visited.at(u) = true;
    if (visited.at(T.at(u))) {
      if (v.at(T.at(u)) == -1) {
        v.at(u) = T.at(u);
        loop.at(u) = 1;
        return;
      } else {
        v.at(u) = v.at(T.at(u));
        //
        return;
      }
    }
    dfs(dfs, T.at(u));
    v.at(u) = v.at(T.at(u));
    loop.at(u) = loop.at(T.at(u)) + 1;
    return;
  };
  for (int u = 0; u < N; u++) {
    if (!visited.at(u)) {
      dfs(dfs, u);
    }
  }
  vector<int> ans(N);
  for (int u = 0; u < N; u++) {
    ans.at(u) = loop.at(v.at(u));
  }
  dump(ans);
  return 0;
}
