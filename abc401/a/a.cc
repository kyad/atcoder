#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int S;
  cin >> S;
  string ans = "Failure";
  if (200 <= S && S <= 299) {
    ans = "Success";
  }
  cout << ans << endl;
  return 0;
}
