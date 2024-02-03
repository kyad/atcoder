#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<string> S(H, string(W, '.'));
  int k = 0;
  int dy[4] = {-1, 0, 1, 0};
  int dx[4] = {0, 1, 0, -1};
  int y = 0;
  int x = 0;
  for (int n = 0; n < N; n++) {
    if (S[y][x] == '.') {  // 白の時
      S[y][x] = '#';
      k = (k + 1) % 4;
    } else {  // 黒の時
      S[y][x] = '.';
      k = (k - 1 + 4) % 4;
    }
    y = (y + dy[k] + H) % H;
    x = (x + dx[k] + W) % W;
  }
  for (string s : S) {
    cout << s << endl;
  }
  return 0;
}
