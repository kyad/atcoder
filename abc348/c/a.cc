#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  map<int, int> mp;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int A, C;
    cin >> A >> C;
    if (mp.contains(C)) {
      mp[C] = min(A, mp[C]);
    } else {
      mp[C] = A;
    }
  }
  int ans = 0;
  for (auto [c, a] : mp) {
    ans = max(ans, a);
  }
  cout << ans << endl;
  return 0;
}
