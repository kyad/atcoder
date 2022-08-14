#include <iostream>
#include <vector>
using namespace std;

static vector<string> B06 = {
  "###...",
  "...###",
  "###...",
  "...###",
  "###...",
  "...###",
};

static vector<string> B07 = {
  "..###..",
  "##....#",
  "#....##",
  "..###..",
  ".#...##",
  "##...#.",
  "..###..",
};

static vector<string> B08 = {
  "##...#..",
  "#...##..",
  "...#..##",
  "..##..#.",
  ".#..##..",
  "##..#...",
  "..##...#",
  "..#...##",
};

static vector<string> B09 = {
  "###......",
  "...###...",
  "......###",
  "###......",
  "...###...",
  "......###",
  "###......",
  "...###...",
  "......###",
};

static vector<string> B10 = {
  "..###.....",
  ".......###",
  "##....#...",
  "#....##...",
  "..###.....",
  ".......###",
  ".#...##...",
  "##...#....",
  "..###.....",
  ".......###",
};

static vector<string> B11 = {
  "##...#.....",
  "#...##.....",
  "........###",
  "...#..##...",
  "..##..#....",
  "........###",
  ".#..##.....",
  "##..#......",
  "........###",
  "..##...#...",
  "..#...##...",
};

static vector<vector<string> > B = { B06, B07, B08, B09, B10, B11 };

int main() {
  int N;
  cin >> N;
  int q = N / 6;
  int r = N % 6;
  vector<string> ans(N, string(N, '.'));
  auto overwrite = [&](int y0, int x0, vector<string> B) {
    int n = B.size();
    for (int y = 0; y < n; y++) {
      for (int x = 0; x < n; x++) {
        ans[y0 + y][x0 + x] = B[y][x];
      }
    }
  };
  for (int k = 0; k < q; k++) {
    int y0 = 6 * k;
    int x0 = 6 * k;
    if (k < q - 1) {
      overwrite(y0, x0, B06);
    } else {
      overwrite(y0, x0, B[r]);
    }
  }
  for (int n = 0; n < N; n++) {
    cout << ans.at(n) << endl;
  }
  return 0;
}
