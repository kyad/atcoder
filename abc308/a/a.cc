#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  N = 8;
  vector<int> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  bool ans = true;
  for (int n = 0; n < N; n++) {
    if (n > 0 && S[n - 1] > S[n]) {
      ans = false;
    }
    if (S[n] < 100 || 675 < S[n]) {
      ans = false;
    }
    if (S[n] % 25) {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
