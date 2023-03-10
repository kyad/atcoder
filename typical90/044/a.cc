#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  int s = 0;
  vector<int> B(N);
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }
  // A[n] =  B.at((n + s) % N
  for (int q = 0; q < Q; q++) {
    int T, x, y;
    cin >> T >> x >> y;
    x--; y--;
    if (T == 1) {
      swap(B[(x + s) % N], B[(y + s) % N]);
    } else if (T == 2) {
      s = (s + N - 1) % N;
    } else {
      cout << B[(x + s) % N] << '\n';
    }
  }
  return 0;
}
