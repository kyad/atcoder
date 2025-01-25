#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  int ymin = H;
  int ymax = -1;
  int xmin = W;
  int xmax = -1;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      if (S.at(y).at(x) == '#') {
        ymin = min(ymin, y);
        ymax = max(ymax, y);
        xmin = min(xmin, x);
        xmax = max(xmax, x);
      }
    }
  }
  for (int y = ymin; y <= ymax; y++) {
    for (int x = xmin; x <= xmax; x++) {
      if (S.at(y).at(x) == '.') {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
