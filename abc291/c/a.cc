#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  set<pair<int, int> > st;
  int x = 0;
  int y = 0;
  st.insert(make_pair(x, y));
  bool ans = false;
  for (int n = 0; n < N; n++) {
    int dx = 0, dy = 0;
    if (S.at(n) == 'R') {
      dx = 1;
    } else if (S.at(n) == 'L') {
      dx = -1;
    } else if (S.at(n) == 'U') {
      dy = 1;
    } else {
      dy = -1;
    }
    x += dx;
    y += dy;
    if (st.count(make_pair(x, y)) > 0) {
      ans = true;
      break;
    }
    st.insert(make_pair(x, y));
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
