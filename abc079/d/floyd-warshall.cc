// https://atcoder.jp/contests/abc079/tasks/abc079_d
// https://github.com/drken1215/book_algorithm_solution/blob/master/codes/chap14/code_14_5.cpp

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int> > c(10, vector<int>(10));
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> c[i][j];
    }
  }
  // Floyd-Warshall algorithm
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }
  int ans = 0;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      int A;
      cin >> A;
      if (A >= 0) {
        ans += c[A][1];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
