#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  int count = 0;
  vector<int> Y(2, 0), X(2, 0);
  for (int y = 0; y < H; y++) {
    string S;
    cin >> S;
    for (int x = 0; x < W; x++) {
      if (S[x] == 'o') {
        Y[count] = y;
        X[count] = x;
        count++;
      }
    }
  }
  int ans = abs(X[0] - X[1]) + abs(Y[0] - Y[1]);
  cout << ans << endl;
  return 0;
}
