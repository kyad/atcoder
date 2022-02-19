#include <iostream>
#include <set>
using namespace std;

int main() {
  int X1, Y1, X2, Y2;
  cin >> X1 >> Y1 >> X2 >> Y2;
  set<pair<int, int> > st;
  const int dx[8] = {2, 1,  -1, -2,  -2, -1,   1,  2 };
  const int dy[8] = {1, 2,   2,  1,  -1, -2,  -2, -1 };
  for (int k = 0; k < 8; k++) {
    int x = X1 + dx[k];
    int y = Y1 + dy[k];
    st.insert(make_pair(x, y));
  }
  bool ans = false;
  for (int k = 0; k < 8; k++) {
    int x = X2 + dx[k];
    int y = Y2 + dy[k];
    if (st.count(make_pair(x, y)) > 0) {
      ans = true;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
