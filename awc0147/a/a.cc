#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = -1;
  int mx = -1;
  for (int i = 1; i <= N; i++) {
    int A;
    cin >> A;
    if (A > mx) {
      mx = A;
      ans = i;
    }
  }
  cout << ans << '\n';
  return 0;
}
