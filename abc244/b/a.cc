#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  string T;
  cin >> T;
  int x = 0;
  int y = 0;
  const int dx[4] = {1, 0, -1, 0};
  const int dy[4] = {0, -1, 0, 1};
  int k = 0;
  for (int n = 0; n < N; n++) {
    if (T[n] == 'S') {
      x += dx[k];
      y += dy[k];
    } else {
      k++;
      k %= 4;
    }
  }
  cout << x << ' ' << y << endl;
  return 0;
}
