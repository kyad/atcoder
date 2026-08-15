#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  string ans = "Nein";
  if (A + B == 9) {
    ans = "Nine";
  }
  if (A - B == 9) {
    ans = "Nine";
  }
  if (A * B == 9) {
    ans = "Nine";
  }
  if (A == 9 * B) {
    ans = "Nine";
  }
  cout << ans << '\n';
  return 0;
}
