#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, N, Q;
  cin >> H >> W >> N >> Q;
  vector<int> R(N), C(N);
  for (int i = 0; i < N; i++) {
    cin >> R.at(i) >> C.at(i);
  }
  sort(R.begin(), R.end());
  sort(C.begin(), C.end());
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    int ans;
    if (type == 1) {
      int u, d;
      cin >> u >> d;
      ans = upper_bound(R.begin(), R.end(), d) - lower_bound(R.begin(), R.end(), u);
    } else {
      int l, r;
      cin >> l >> r;
      ans = upper_bound(C.begin(), C.end(), r) - lower_bound(C.begin(), C.end(), l);
    }
    cout << ans << '\n';
  }
  return 0;
}
