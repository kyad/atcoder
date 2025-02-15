#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  map<pair<int, int>, int> mp;
  for (int j = 0; j < M; j++) {
    int u, v;
    cin >> u >> v;
    if (u < v) {
      swap(u, v);
    }
    mp[make_pair(u, v)]++;
  }
  int ans = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    int u = it->first.first;
    int v = it->first.second;
    int count = it->second;
    if (u == v) {
      ans += count;
    } else {
      ans += (count - 1);
    }
  }
  cout << ans << endl;
  return 0;
}
