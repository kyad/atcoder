#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  map<char, int> mp;
  for (char c : S) {
    mp[c]++;
  }
  char ans = '.';
  for (auto [c, count] : mp) {
    if (count == 1) {
      ans = c;
    }
  }
  cout << ans << endl;
  return 0;
}
