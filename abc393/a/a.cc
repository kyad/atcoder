#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S1, S2;
  cin >> S1 >> S2;
  int ans = -1;
  if (S1 == "sick" && S2 == "sick") {
    ans = 1;
  } else if (S1 == "sick" && S2 == "fine") {
    ans = 2;
  } else if (S1 == "fine" && S2 == "sick") {
    ans = 3;
  } else {
    ans = 4;
  }
  cout << ans << endl;
  return 0;
}
