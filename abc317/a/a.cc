#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, H, X;
  cin >> N >> H >> X;
  for (int n = 0; n < N; n++) {
    int P;
    cin >> P;
    if (P + H >= X) {
      cout << (n + 1) << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
