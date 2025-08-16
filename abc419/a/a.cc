#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  map<string, string> mp;
  mp["red"] = "SSS";
  mp["blue"] = "FFF";
  mp["green"] = "MMM";
  string S;
  cin >> S;
  string ans = "Unknown";
  if (mp.contains(S)) {
    ans = mp[S];
  }
  cout << ans << endl;
  return 0;
}
