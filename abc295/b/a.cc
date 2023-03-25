#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int R, C;
  cin >> R >> C;
  vector<string> B(R);
  for (int n = 0; n < R; n++) {
    cin >> B.at(n);
  }
  for (int i = 1; i <= 9; i++) {
    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        if (B[y][x] == ('0' + i)) {
          B[y][x] = '.';
          for (int ny = 0; ny < R; ny++) {
            for (int nx = 0; nx < C; nx++) {
              if (B[ny][nx] == '#' && (abs(ny - y) + abs(nx - x) <= i)) {
                B[ny][nx] = '.';
              }
            }
          }
        }
      }
    }
  }
  for (int y = 0; y < R; y++) {
    cout << B[y] << endl;
  }
  return 0;
}
