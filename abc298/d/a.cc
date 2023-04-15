#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// modint
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
ostream& operator<<(ostream& os, const mint &v) {
  os << v.val();
  return os;
}

int main() {
  int Q;
  cin >> Q;
  queue<int> que;
  que.push(1);
  mint a(1);
  mint d(1);
  for (int q = 0; q < Q; q++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      que.push(x);
      mint mx(x);
      a *= 10;
      a += mx;
      d *= 10;
    } else if (type == 2) {
      int x = que.front();
      a -= (d * x);
      d /= 10;
      que.pop();
    } else {
      cout << a << '\n';
    }
  }
  return 0;
}
