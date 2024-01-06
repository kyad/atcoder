#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> X(N, 0), Y(N, 0);
  for (int i = 0; i < N; i++) {
    X[i] = i + 1;
  }
  int px = 0;
  int py = 0;
  int x = 1;
  int y = 0;
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      char C;
      cin >> C;
      if (C == 'R') {
        x++;
      } else if (C == 'L') {
        x--;
      } else if (C == 'U') {
        y++;
      } else {
        y--;
      }
      px = (px - 1 + N) % N;
      py = (py - 1 + N) % N;
      X[px] = x;
      Y[py] = y;
    } else { // type == 2
      int p;
      cin >> p;
      p--;
      cout << X[(px + p) % N] << ' ' << Y[(py + p) % N] << '\n';
    }
  }
  return 0;
}
