#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, Q;
  cin >> H >> W >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int R;
      cin >> R;
      int ans = W * R;
      cout << ans << '\n';
      H -= R;
    } else {
      int C;
      cin >> C;
      int ans = H * C;
      cout << ans << '\n';
      W -= C;
    }
  }
  return 0;
}
