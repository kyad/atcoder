#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int r = 0;
  int w = 0;
  int o = 0;
  for (int i = 0; i < N; i++) {
    char S;
    cin >> S;
    if (S == 'R') {
      r++;
    } else if (S == 'W') {
      w++;
    } else {
      o++;
    }
  }
  for (int j = 0; j < o; j++) {
    if (r < w) {
      r++;
    } else if (r > w) {
      w++;
    } else {
      r++;
    }
  }
  int ans = abs(r - w);
  cout << ans << '\n';
  return 0;
}
