#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main() {
  int H, W, M;
  cin >> H >> W >> M;
  vector<int> T(M), A(M), X(M);
  for (int m = 0; m < M; m++) {
    cin >> T.at(m) >> A.at(m) >> X.at(m);
    A.at(m)--;
  }
  map<int, long long> mp;
  set<int> R, C;
  for (int m = M - 1; m >= 0; m--) {
    if (T[m] == 1) {
      int y = A[m];
      if (R.contains(y)) {
        continue;
      }
      long long now = W - C.size();
      assert(now >= 0LL);
      if (now == 0) {
        continue;
      }
      mp[X[m]] += now;
      R.insert(y);
    } else {
      int x = A[m];
      if (C.contains(x)) {
        continue;
      }
      long long now = H - R.size();
      assert(now >= 0LL);
      if (now == 0) {
        continue;
      }
      mp[X[m]] += now;
      C.insert(x);
    }
  }
  long long resi = (long long)(H - R.size()) * (long long)(W - C.size());
  if (resi > 0) {
    mp[0] += resi;
  }
  // 答
  int K = mp.size();
  cout << K << endl;
  for (auto [c, x] : mp) {
    assert(x > 0);
    cout << c << ' ' << x << '\n';
  }
  return 0;
}
