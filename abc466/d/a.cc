#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<set<int>> Y(N + 1), X(N + 1);
  set<pair<int, int>> st;
  for (int j = 0; j < M; j++) {
    int R, C;
    cin >> R >> C;
    for (int x : Y.at(R)) {
      auto p = make_pair(R, x);
      if (st.contains(p)) {
        st.erase(p);
      }
    }
    Y.at(R).clear();
    for (int y : X.at(C)) {
      auto p = make_pair(y, C);
      if (st.contains(p)) {
        st.erase(p);
      }
    }
    X.at(C).clear();
    st.insert(make_pair(R, C));
    Y.at(R).insert(C);
    X.at(C).insert(R);
  }
  int ans = st.size();
  cout << ans << '\n';
  return 0;
}
