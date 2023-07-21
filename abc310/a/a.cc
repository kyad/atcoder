#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, P, Q;
  cin >> N >> P >> Q;
  int ans = P;
  for (int n = 0; n < N; n++) {
    int D;
    cin >> D;
    ans = min(ans, Q + D);
  }
  cout << ans << endl;
  return 0;
}
