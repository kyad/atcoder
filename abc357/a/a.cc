#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int ans = 0;
  for (int n = 0; n < N; n++) {
    int H;
    cin >> H;
    M -= H;
    if (M >= 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
