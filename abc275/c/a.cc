#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<string> S(9);
  for (int r = 0; r < 9; r++) {
    cin >> S.at(r);
  }
  int ans = 0;
  for (int r0 = 0; r0 < 9; r0++) {
    for (int c0 = 0; c0 < 9; c0++) {
      if (S[r0][c0] == '.') {
        continue;
      }
      for (int r1 = r0 + 1; r1 < 9; r1++) {
        for (int c1 = c0; c1 < 9; c1++) {
          if (S[r1][c1] == '.') {
            continue;
          }
          int dr = r1 - r0;
          int dc = c1 - c0;
          int r2 = r0 + dc;
          int c2 = c0 - dr;
          int r3 = r1 + dc;
          int c3 = c1 - dr;
          if (r2 < 0 || r2 >= 9 || c2 < 0 || c2 >= 9) {
            continue;
          }
          if (r3 < 0 || r3 >= 9 || c3 < 0 || c3 >= 9) {
            continue;
          }
          if (S[r2][c2] == '.') {
            continue;
          }
          if (S[r3][c3] == '.') {
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
