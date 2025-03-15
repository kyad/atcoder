#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  double X;
  cin >> X;
  int ans;
  if (X >= 38) {
    ans = 1;
  } else if (X >= 37.5) {
    ans = 2;
  } else {
    ans = 3;
  }
  cout << ans << endl;
  return 0;
}
