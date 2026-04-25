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
  int ans = 0;
  for (int h1 = 0; h1 < H; h1++) {
    for (int h2 = h1; h2 < H; h2++) {
      for (int w1 = 0; w1 < W; w1++) {
        for (int w2 = w1; w2 < W; w2++) {
          bool ok = true;
          for (int i = h1; i <= h2; i++) {
            for (int j = w1; j <= w2; j++) {
              if (S.at(i).at(j) != S.at(h1 + h2 - i).at(w1 + w2 - j)) {
                ok = false;
              }
            }
          }
          if (ok) ans++;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
