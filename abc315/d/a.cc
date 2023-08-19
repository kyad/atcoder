#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> C(H);
  for (int y = 0; y < H; y++) {
    cin >> C.at(y);
  }
  vector<vector<int> > row(H, vector<int>(26, 0));
  vector<vector<int> > col(W, vector<int>(26, 0));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      int c = C[y][x] - 'a';
      assert(0 <= c && c < 26);
      row[y][c]++;
      col[x][c]++;
    }
  }
  vector<bool> use_row(H, true);
  vector<bool> use_col(W, true);
  while (true) {  // <=min(H, W) <=2000
    // Check size
    int h = count(use_row.begin(), use_row.end(), true);
    int w = count(use_col.begin(), use_col.end(), true);

    if (h <= 1 || w <= 1) {
      break;
    }

    // Step 1
    vector<pair<int, int> > ys;
    for (int y = 0; y < H; y++) {
      if (!use_row[y]) {
        continue;
      }
      for (int c = 0; c < 26; c++) {
        if (row[y][c] == w) {
          use_row[y] = false;
          ys.push_back(make_pair(y, c));
        }
      }
    }

    // Step 2
    vector<pair<int, int> > xs;
    for (int x = 0; x < W; x++) {
      if (!use_col[x]) {
        continue;
      }
      for (int c = 0; c < 26; c++) {
        if (col[x][c] == h) {
          use_col[x] = false;
          xs.push_back(make_pair(x, c));
        }
      }
    }

    if (ys.empty() && xs.empty()) {
      break;
    }

    // Delete
    for (auto [y, c] : ys) {
      for (int x = 0; x < W; x++) {
        col[x][c]--;
      }
    }
    for (auto [x, c] : xs) {
      for (int y = 0; y < H; y++) {
        row[y][c]--;
      }
    }
  }

  int h = count(use_row.begin(), use_row.end(), true);
  int w = count(use_col.begin(), use_col.end(), true);
  int ans = h * w;
  cout << ans << endl;
  return 0;
}
