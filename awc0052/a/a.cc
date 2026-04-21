#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  int prev = -100;
  int now = 0;
  int ans = -1;
  for (int i = 0; i < N; i++) {
    if (prev < A.at(i)) {
      now++;
      ans = max(ans, now);
    } else {
      now = 1;
    }
    prev = A.at(i);
  }

  cout << ans << '\n';
  return 0;
}
