#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int> > B(W, vector<int>(H, 0));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> B[j][i];
    }
  }
  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      cout << B[i][j];
      if (j == H - 1) {
        cout << endl;
      } else {
        cout << ' ';
      }
    }
  }
  return 0;
}
