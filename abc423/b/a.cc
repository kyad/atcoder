#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
  }
  int left = 1;
  for (int i = 0; i < N; i++) {
    if (L.at(i) == 0) {
      left++;
    } else {
      break;
    }
  }
  int right = 1;
  for (int i = N - 1; i >= 0; i--) {
    if (L.at(i) == 0) {
      right++;
    } else {
      break;
    }
  }
  int ans = (N + 1) - left - right;
  ans = max(ans, 0);
  cout << ans << endl;
  return 0;
}
