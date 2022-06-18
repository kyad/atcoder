#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> H(3), W(3);
  for (int i = 0; i < 3; i++) {
    cin >> H.at(i);
  }
  for (int i = 0; i < 3; i++) {
    cin >> W.at(i);
  }
  vector<vector<int> > a(3, vector<int>(3, 0));
  int ans = 0;
  for (a[0][0] = 1; a[0][0] <= min(H[0], W[0]); a[0][0]++) {
    for (a[0][1] = 1; a[0][1] <= min(H[0], W[1]); a[0][1]++) {
      a[0][2] = H[0] - a[0][0] - a[0][1];
      if (a[0][2] <= 0) {
        continue;
      }
      for (a[1][0] = 1; a[1][0] <= min(H[1], W[0]); a[1][0]++) {
        for (a[1][1] = 1; a[1][1] <= min(H[1], W[1]); a[1][1]++) {
          a[1][2] = H[1] - a[1][0] - a[1][1];
          if (a[1][2] <= 0) {
            continue;
          }
          bool ok = true;
          for (int x = 0; x < 3; x++) {
            a[2][x] = W[x] - a[0][x] - a[1][x];
            if (a[2][x] <= 0) {
              ok = false;
              break;
            }
          }
          if (!ok) {
            continue;
          }
          int sum = 0;
          for (int x = 0; x < 3; x++) {
            sum += a[2][x];
          }
          if (sum != H[2]) {
            continue;
          }
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
