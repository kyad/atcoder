#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> count(N + 1, 0);
  for (int q = 0; q < Q; q++) {
    int c, x;
    cin >> c >> x;
    if (c == 1) {
      count[x]++;
    } else if (c == 2) {
      count[x] = 2;
    } else {
      bool ans = (count[x] >= 2);
      cout << (ans ? "Yes" : "No") << '\n';
    }
  }
  return 0;
}
