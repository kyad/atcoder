#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  set<int> S;
  int nx = 1;
  for (int q = 0; q < Q; q++) {
    int type;
    cin >> type;
    if (type == 1) {
      S.insert(nx);
      nx++;
    } else if (type == 2) {
      int x;
      cin >> x;
      S.erase(x);
    } else {
      int ans = *S.begin();
      cout << ans << '\n';
    }
  }
  return 0;
}
