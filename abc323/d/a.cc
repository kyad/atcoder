#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  long long ans = 0;
  int N;
  cin >> N;
  map<long long, long long> mp;
  for (int n = 0; n < N; n++) {
    int S, C;
    cin >> S >> C;
    mp[S] = C;
  }
  while (!mp.empty()) {
    long long S = mp.begin()->first;
    long long C = mp.begin()->second;
    if (C >= 2) {
      mp[S * 2] += C / 2;
    }
    ans += C % 2;
    mp.erase(mp.begin());
  }
  cout << ans << endl;
  return 0;
}
