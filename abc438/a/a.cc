#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int D, F;
  cin >> D >> F;
  int day = F - 1;
  while (true) {
    if (day >= D) {
      int ans = day - D + 1;
      cout << ans << '\n';
      break;
    }
    day += 7;
  }
  return 0;
}
