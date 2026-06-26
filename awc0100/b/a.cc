#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  int mx = -1;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    int now = A + B;
    if (now > mx) {
      ans = i + 1;
      mx = now;
    }
  }
  cout << ans << '\n';
  return 0;
}
