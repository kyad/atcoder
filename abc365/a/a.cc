#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int Y;
  cin >> Y;
  int ans;
  if (Y % 400 == 0) {
    ans = 366;
  } else if (Y % 100 == 0) {
    ans = 365;
  } else if (Y % 4 == 0) {
    ans = 366;
  } else {
    ans = 365;
  }
  cout << ans << endl;
  return 0;
}
