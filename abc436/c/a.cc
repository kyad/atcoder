#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  long long N;
  int M;
  cin >> N >> M;
  set<pair<int, int> > st;
  for (int j = 0; j < M; j++) {
    int R, C;
    cin >> R >> C;
    bool ok = true;
    for (int y = R; y <= R + 1; y++) {
      for (int x = C; x <= C + 1; x++) {
        if (st.contains(make_pair(y, x))) {
          ok = false;
        }
      }
    }
    if (ok) {
      for (int y = R; y <= R + 1; y++) {
        for (int x = C; x <= C + 1; x++) {
          st.insert(make_pair(y, x));
        }
      }
    }
  }
  long long ans = st.size() / 4;
  cout << ans << '\n';
  return 0;
}
