#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  int ans = 0;
  for (int y = 0; y < H; y++) {
    string S;
    cin >> S;
    for (int x = 0; x < W; x++) {
      if (S.at(x) == '#') {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
