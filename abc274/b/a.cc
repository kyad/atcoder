#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<int> X(W, 0);
  for (int y = 0; y < H; y++) {
    string C;
    cin >> C;
    for (int x = 0; x < W; x++) {
      if (C.at(x) == '#') {
        X.at(x)++;
      }
    }
  }
  for (int x = 0; x < W; x++) {
    cout << X.at(x);
    if (x == W - 1) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  return 0;
}
