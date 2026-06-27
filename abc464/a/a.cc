#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int E = 0;
  int W = 0;
  for (char c : S) {
    if (c == 'E') {
      E++;
    } else {
      W++;
    }
  }
  string ans;
  if (E > W) {
    ans = "East";
  } else {
    ans = "West";
  }
  cout << ans << '\n';
  return 0;
}
