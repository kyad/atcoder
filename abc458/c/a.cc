#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'C') {
      long long left = i + 1;
      long long right = N - i;
      long long now = min(left, right);
      ans += now;
    }
  }
  cout << ans << '\n';
  return 0;
}
