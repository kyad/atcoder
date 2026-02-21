#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  S.at(0) += ('a' - 'A');
  string ans = "Of" + S;
  cout << ans << '\n';
  return 0;
}
