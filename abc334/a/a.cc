#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int B, G;
  cin >> B >> G;
  string ans;
  if (B > G) {
    ans = "Bat";
  } else {
    ans = "Glove";
  }
  cout << ans << endl;
  return 0;
}
