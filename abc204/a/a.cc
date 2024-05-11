#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  int ans  =-1;
  if (x == y) {
    ans = x;
  } else {
    ans = 3 - x - y;
  }
  cout << ans << endl;
  return 0;
}
