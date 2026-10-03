#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    int ans;
    if (M % N != 0 && i < M % N) {
      ans = M / N + 1;
    } else {
      ans = M / N;
    }
    cout << ans << endl;
  }
  return 0;
}
