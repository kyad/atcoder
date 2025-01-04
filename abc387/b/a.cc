#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int X;
  cin >> X;
  int ans = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      int now = i * j;
      if (now == X) {
        continue;
      }
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}
