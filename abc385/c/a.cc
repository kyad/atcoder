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
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  // is[h]: 高さhのビルのindexの集合
  vector<set<int> > is(3001);
  for (int i = 0; i < N; i++) {
    is.at(H.at(i)).insert(i);
  }
  int ans = 0;
  for (int h = 1; h <= 3000; h++) {  // 高さを固
    int now = 0;
    for (int w = 1; w < 3000; w++) {
      map<int, int> mp;
      for (int i : is.at(h)) {
        mp[i] = mp[i - w] + 1;
      }
      int max_v = 0;
      for (auto [k, v] : mp) {
        max_v = max(max_v, v);
      }
      now = max(now, max_v);
    }
    ans = max(ans, now);
  }

  cout << ans << endl;
  return 0;
}
