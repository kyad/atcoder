#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int dr[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dc[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void dump(int r1, int c1, int k) {
  for (int i = 0; i < 5; i++) {
    int r = r1 + dr[k] * i;
    int c = c1 + dc[k] * i;
    cout << (r + 1) << " " << (c + 1) << endl;
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }
  string snuke = "snuke";
  for (int r1 = 0; r1 < H; r1++) {
    for (int c1 = 0; c1 < W; c1++) {
      for (int k = 0; k < 8; k++) {
        bool ok = true;
        for (int i = 0; i < 5; i++) {
          int r = r1 + dr[k] * i;
          int c = c1 + dc[k] * i;
          if (r < 0 || r >= H || c < 0 || c >= W) {
            ok = false;
            break;
          }
          if (S[r][c] != snuke[i]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          dump(r1, c1, k);
          return 0;
        }
      }
    }
  }
  return 0;
}

