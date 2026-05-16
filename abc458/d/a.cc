#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int X;
  cin >> X;
  priority_queue<int> L;
  priority_queue<int, vector<int>, greater<int>> R;
  R.push(X);
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int A, B;
    cin >> A >> B;
    // Aを入れる
    {
      int r = R.top();
      if (A <= r) {
        L.push(A);
      } else {
        R.pop();
        L.push(r);
        R.push(A);
      }
      assert((int)L.size() == 1 + q);
      assert((int)R.size() == 1 + q);
    }
    // Bを入れる
    {
      int l = L.top();
      if (l <= B) {
        R.push(B);
      } else {
        L.pop();
        R.push(l);
        L.push(B);
        assert((int)L.size() == 1 + q);
        assert((int)R.size() == 2 + q);
      }
    }
    int ans = R.top();
    cout << ans << '\n';
  }
  return 0;
}
