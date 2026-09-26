#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  char c;
  cin >> c;
  char ans;
  if (c == 'B') {
    ans = 'Y';
  } else if (c == 'Y') {
    ans = 'R';
  } else {
    ans = 'B';
  }
  cout << ans << '\n';
  return 0;
}
