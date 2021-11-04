// https://atcoder.jp/contests/gigacode-2019/tasks/gigacode_2019_d

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  long long V;
  cin >> H >> W >> K >> V;
  vector<vector<long long> > A(H + 1, vector<long long>(W + 1, 0));
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      cin >> A[y][x];
      A[y][x] += K;
    }
  }
  for (int y = 1; y <= H; y++) {
    for (int x = 1; x <= W; x++) {
      A[y][x] = A[y][x] + A[y - 1][x] + A[y][x - 1] - A[y - 1][x - 1];
    }
  }
  int ans = 0;
  for (int y0 = 1; y0 <= H; y0++) {
    for (int y1 = y0; y1 <= H; y1++) {
      for (int x0 = 1; x0 <= W; x0++) {
        for (int x1 = x0; x1 <= W; x1++) {
          long long cost = A[y1][x1] - A[y1][x0 - 1] - A[y0 - 1][x1] + A[y0 - 1][x0 - 1];
          if (cost <= V) {
            int area = (y1 - y0 + 1) * (x1 - x0 + 1);
            ans = max(ans, area);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
