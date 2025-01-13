#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  for (int i = 0; i < N; i++) cin >> X.at(i);
  vector<long long> P(N);
  for (int i = 0; i < N; i++) cin >> P.at(i);
  map<int, long long> mp;
  mp[-1e9-1] = 0;  // 番兵
  for (int i = 0; i < N; i++) {
    mp[X.at(i)] = P.at(i);
  }
  map<int, long long> sum;
  long long pre = 0;
  for (map<int, long long>::iterator it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) {
      sum[it->first] = it->second + pre;
      pre = sum[it->first];
    } else {
      sum[it->first] = 0;
    }
  }
  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    long long L, R;
    cin >> L >> R;
    long long ans = prev(sum.upper_bound(R))->second - prev(sum.lower_bound(L))->second;
    cout << ans << '\n';
  }
  return 0;
}
