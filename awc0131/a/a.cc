#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int _N = N;
  int ans = 0;
  for (int i = 0; i < _N; i++) {
    int F;
    cin >> F;
    int a = min(N, F);
    N -= a;
    if (N >= 1) {
      N--;
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
