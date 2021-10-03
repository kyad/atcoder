// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int R, C;
  cin >> R >> C;
  vector<vector<int> > mat0(R, vector<int>(C));
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cin >> mat0.at(r).at(c);
    }
  }
  int ans = 0;
  for (int b = 0; b < (1<<R); b++) {  // 1024
    vector<vector<int> > mat(R, vector<int>(C));
    for (int r = 0; r < R; r++) {  // 1024 * 10
      if (b>>r&1) {
        for (int c = 0; c < C; c++) {  // 1024 * 10 * 1000
          mat.at(r).at(c) = 1 - mat0.at(r).at(c);
        }
      } else {
        for (int c = 0; c < C; c++) {
          mat.at(r).at(c) = mat0.at(r).at(c);
        }
      }
    }
    int temp = 0;
    for (int c = 0; c < C; c++) {  // 1024 * 10
      int count = 0;
      for (int r = 0; r < R; r++) {  // 1024 * 10 * 1000
        if (mat.at(r).at(c) == 0) {
          count++;
        }
      }
      temp += max(count, R - count);
    }
    ans = max(ans, temp);
  }
  cout << ans << endl;
  return 0;
}
