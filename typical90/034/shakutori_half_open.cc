#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  map<int, int> mp;
  auto check_next = [&](int r) -> bool {
    if (r >= N) {
      return false;
    }
    int nsz = mp.size();
    if (mp.count(A[r]) == 0) {
      nsz++;
    }
    if (nsz > K) {
      return false;
    }
    return true;
  };
  int r = 0;
  int ans = -1;
  // [l, r)で尺取り法
  for (int l = 0; l < N; l++) {
    while (check_next(r)) {
      mp[A[r]]++;
      r++;
    }
    ans = max(ans, r - l);
    if (r == l) {
      r++;
    }
    assert(mp.count(A[l]) >= 1);
    if (mp[A[l]] == 1) {
      mp.erase(A[l]);
    } else {
      mp[A[l]]--;
    }
  }
  cout << ans << endl;
  return 0;
}
