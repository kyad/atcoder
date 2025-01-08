#include <iostream>
#include <cassert>

using namespace std;

int main() {
  char AB, AC, BC;
  cin >> AB >> AC >> BC;
  char ans;
  if (AB == BC) {
    ans = 'B';
  } else if (AB != AC) {
    ans = 'A';
  } else if (AC != BC) {
    ans = 'C';
  } else {
    assert(false);
  }
  cout << ans << endl;
  return 0;
}