#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  for (int y = 0; y < H; y++) {
    string S;
    for (int x = 0; x < W; x++) {
      int A;
      cin >> A;
      if (A == 0) {
        S.push_back('.');
      } else {
        S.push_back('A' + (A - 1));
      }
    }
    cout << S << endl;
  }
  return 0;
}
