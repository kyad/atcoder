#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int ans = 0;
  int zero = 0;
  for (int n = 0; n < N; n++) {
    if (S[n] != '0') {
      ans += ceildiv(zero, 2);
      zero = 0;
      ans += 1;
    } else {
      zero++;
    }
  }
  ans += ceildiv(zero, 2);
  cout << ans << endl;
  return 0;
}
