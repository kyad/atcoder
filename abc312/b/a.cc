#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int d_inf(int y0, int x0, int y1, int x1) {
  return max(abs(y0 - y1), abs(x0 - x1));
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  for (int y0 = 0; y0 < N; y0++) {
    int y1 = y0 + 9 - 1;
    if (y1 >= N) {
      continue;
    }
    for (int x0 = 0; x0 < M; x0++) {
      int x1 = x0 + 9 - 1;
      if (x1 >= M) {
        continue;
      }
      auto check = [&]() -> bool {
        for (int y = y0; y <= y0 + 3; y++) {
          for (int x = x0; x <= x0 + 3; x++) {
            char expected = '#';
            if (d_inf(y, x, y0, x0) == 3) {
              expected = '.';
            }
            if (S[y][x] != expected) {
              return false;
            }
          }
        }
        for (int y = y1; y >= y1 - 3; y--) {
          for (int x = x1; x >= x1 - 3; x--) {
            char expected = '#';
            if (d_inf(y, x, y1, x1) == 3) {
              expected = '.';
            }
            if (S[y][x] != expected) {
              return false;
            }
          }
        }
        return true;
      };
      if (check()) {
        cout << (y0 + 1) << ' ' << (x0 + 1) << '\n';
      }
    }
  }
  return 0;
}
