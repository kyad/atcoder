#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int> > A(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }
  string ans = "Yes";
  for (int i1 = 0; i1 < H; i1++) {
    for (int i2 = i1 + 1; i2 < H; i2++) {
      for (int j1 = 0; j1 < W; j1++) {
        for (int j2 = j1 + 1; j2 < W; j2++) {
          if (A[i1][j1] + A[i2][j2] > A[i2][j1] + A[i1][j2]) {
            ans = "No";
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
