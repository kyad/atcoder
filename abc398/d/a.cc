#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  int N, R, C;
  cin >> N >> R >> C;
  string S;
  cin >> S;
  map<pair<int, int>, bool> board;
  // 焚き火の位置
  int ty = 0;
  int tx = 0;
  board[make_pair(ty, tx)] = true;
  // 人の位置
  int py = R;
  int px = C;
  string ans;
  for (int i = 0; i < N; i++) {
    int dy, dx;
    if (S.at(i) == 'N') {
      dy = +1;
      dx = 0;
    } else if (S.at(i) == 'W') {
      dy = 0;
      dx = +1;
    } else if (S.at(i) == 'S') {
      dy = -1;
      dx = 0;
    } else  {
      dy = 0;
      dx = -1;
    }
    // 焚き火を移動
    ty += dy;
    tx += dx;
    // 人を移動
    py += dy;
    px += dx;
    board[make_pair(ty, tx)] = true;
    pair<int, int> p = make_pair(py, px);
    if (board.contains(p) && board[p] == true) {
      ans.push_back('1');
    } else {
      ans.push_back('0');
    }
  }
  cout << ans << endl;
  return 0;
}
