#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int K, G, M;
  cin >> K >> G >> M;
  int g = 0;
  int m = 0;
  auto f = [&]() {
    if (g == G) {
      g = 0;
    } else if (m == 0) {
      m = M;
    } else {
      int x = min(G - g, m);
      g += x;
      m -= x;
    }
    assert(0 <= g && g <= G);
    assert(0 <= m && m <= M);
  };
  for (int k = 0; k < K; k++) {
    f();
    //cout << k << ' ' << g << ' ' << m << endl;
  }
  cout << g << ' ' << m << endl;
  return 0;
}
