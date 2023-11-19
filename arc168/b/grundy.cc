#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  long long G = 0;
  for (int n = 0; n < N; n++) {
    G ^= A.at(n);
  }

  // 普通のNimでAliceが勝ち
  if (G != 0LL) {
    cout << -1 << endl;
    return 0;
  }

  map<long long, int> mp;
  for (int n = 0; n < N; n++) {
    mp[A[n]]++;
  }
  for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    int count = it->second;
    if (count % 2 == 0) {
      continue;
    }
    long long A = it->first;
    long long k = A - 1;
    cout << k << endl;
    return 0;
  }
  long long ans = 0;
  cout << ans << endl;
  return 0;
}
