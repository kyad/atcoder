#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  string ans = "_UPC";
  ans.at(0) = S.at(0);
  cout << ans << endl;
  return 0;
}
