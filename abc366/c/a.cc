#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  map<int, int> mp;
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      mp[x]++;
    } else if (type == 2) {
      int x;
      cin >> x;
      assert(mp[x] >= 1);
      mp[x]--;
      if (mp[x] == 0) {
        mp.erase(x);
      }
    } else {
      int ans = mp.size();
      cout << ans << '\n';
    }
  }
  return 0;
}
