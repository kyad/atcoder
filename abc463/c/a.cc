#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N), L(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i) >> L.at(i);
  }
  map<int, int> mp;
  mp[0] = *max_element(H.begin(), H.end());
  multiset<int> ms;
  for (int i = 0; i < N; i++) {
    ms.insert(H.at(i));
  }
  for (int i = 0; i < N; i++) {
    int h = H.at(i);
    int l = L.at(i);
    ms.erase(ms.find(h));
    int mx = -1;
    if (i != N - 1) {
      assert(!ms.empty());
      mx = *ms.rbegin();
    }
    if (mp.contains(l)) {
      mp[l] = min(mp[l], mx);
    } else {
      mp[l] = mx;
    }
  }
  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int T;
    cin >> T;
    int ans = prev(mp.upper_bound(T))->second;
    cout << ans << '\n';
  }
  return 0;
}
