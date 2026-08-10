#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  int ans = 1;
  int mx = H.at(N - 1);
  for (int i = N - 2; i >= 0; i--) {
    if (H.at(i) < mx) {
    } else {
      mx = H.at(i);
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
