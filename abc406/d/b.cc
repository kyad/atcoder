#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> Y(N), X(N);
  for (int i = 0; i < N; i++) {
    cin >> Y.at(i) >> X.at(i);
    Y.at(i)--; X.at(i)--;
  }
  vector<int> A(W, 0), B(H, 0);
  vector<vector<int> > ys(W), xs(H);
  set<pair<int, int> > st;
  for (int i = 0; i < N; i++) {
    int x = X.at(i);
    int y = Y.at(i);
    A.at(x)++;
    ys.at(x).push_back(y);
    B.at(y)++;
    xs.at(y).push_back(x);
    st.insert(make_pair(y, x));
  }
  int Q;
  cin >> Q;
  vector<bool> C(W, false), D(H, false);
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int y;
      cin >> y;
      y--;
      cout << B.at(y) << '\n';
      B.at(y) = 0;
      if (D.at(y) == false) {
        for (int x : xs.at(y)) {
          if (st.contains(make_pair(y, x))) {
            st.erase(make_pair(y, x));
            A.at(x)--;
          }
        }
        D.at(y) = true;
      }
    } else {
      int x;
      cin >> x;
      x--;
      cout << A.at(x) << '\n';
      A.at(x) = 0;
      if (C.at(x) == false) {
        for (int y : ys.at(x)) {
          if (st.contains(make_pair(y, x))) {
            st.erase(make_pair(y, x));
            B.at(y)--;
          }
        }
        C.at(x) = true;
      }
    }
  }
  return 0;
}
