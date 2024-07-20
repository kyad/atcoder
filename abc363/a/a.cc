#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int R = 0;
  cin >> R;
  int r = R / 100;
  int ans = 0;
  while (true) {
    R++;
    ans++;
    int nr = R / 100;
    if (nr > r) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
