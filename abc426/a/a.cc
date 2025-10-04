#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  string X, Y;
  cin >> X >> Y;
  map<string, int> mp;
  mp["Ocelot"] = 1;
  mp["Serval"] = 2;
  mp["Lynx"] = 3;
  bool ans;
  if (mp[X] >= mp[Y]) {
    ans = true;
  } else {
    ans = false;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
