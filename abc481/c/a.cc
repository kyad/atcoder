#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  map<string, int> mp;
  int id = 1;
  for (int qi = 0; qi < Q; qi++) {
    string S;
    cin >> S;
    if (mp.contains(S)) {
      cout << mp[S] << '\n';
    } else {
      cout << id << '\n';
      mp[S] = id;
      id++;
    }
  }
  return 0;
}
