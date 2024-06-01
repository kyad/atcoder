#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  vector<int> A(T);
  for (int n = 0; n < T; n++) {
    cin >> A.at(n);
  }
  vector<int> R(N, N), C(N, N), D(2, N);
  auto f = [&](int T) -> bool {
    T--;
    int y = T / N;
    int x = T % N;
    bool ans = false;
    R.at(y)--;
    if (R.at(y) == 0) {
      ans = true;
    }
    C.at(x)--;
    if (C.at(x) == 0) {
      ans = true;
    }
    if (x == y) {
      D.at(0)--;
      if (D.at(0) == 0) {
        ans = true;
      }
    }
    if (x + y == N - 1) {
      D.at(1)--;
      if (D.at(1) == 0) {
        ans = true;
      }
    }
    return ans;
  };
  int ans = -1;
  for (int t = 0; t < T; t++) {
    bool now = f(A.at(t));
    if (now) {
      ans = t + 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
