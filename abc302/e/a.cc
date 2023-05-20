#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  set<int> z;
  for (int n = 0; n < N; n++) {
    z.insert(n);
  }
  vector<set<int> > st(N);
  for (int q = 0; q < Q; q++) {
    int type;
    cin >> type;
    if (type == 1) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      st[u].insert(v);
      st[v].insert(u);
      if (z.count(u) > 0) {
        z.erase(u);
      }
      if (z.count(v) > 0) {
        z.erase(v);
      }
    } else {
      int u;
      cin >> u;
      u--;
      for (int v : st[u]) {
        assert(st[v].count(u) > 0);
        st[v].erase(u);
        if (st[v].empty()) {
          z.insert(v);
        }
      }
      st[u].clear();
      z.insert(u);
    }
    cout << z.size() << '\n';
  }
  return 0;
}
