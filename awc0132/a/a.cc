#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, P;
  cin >> N >> P;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (P >= H.at(i)) {
      P -= H.at(i);
      ans++;
    } else {
      P += H.at(i);
    }
  }
  cout << ans << '\n';
  return 0;
}
