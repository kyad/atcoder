#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int Q;
  vector<int> A;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      A.push_back(x);
    } else {
      int k;
      cin >> k;
      int N = A.size();
      int ans = A.at(N - k);
      cout << ans << '\n';
    }
  }
  return 0;
}
