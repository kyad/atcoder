#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  long long N;
  cin >> N;
  map<long long, long long> mp;
  mp[-N] = 1;
  long long ans = 0;
  while (!mp.empty()) {
    long long x = -(mp.begin()->first);
    if (x <= 1) {
      break;
    }
    long long cnt = mp.begin()->second;
    long long now = x * cnt;
    ans += now;
    mp.erase(mp.begin());
    mp[-(x/2)] += cnt;
    mp[-((x + 1)/2)] += cnt;
  }
  cout << ans << endl;
  return 0;
}
