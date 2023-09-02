#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, P;
  cin >> N >> M >> P;
  if (N - M < 0) {
    cout << 0 << endl;
    return 0;
  }
  int ans = (N - M) / P + 1;
  cout << ans << endl;
  return 0;
}
