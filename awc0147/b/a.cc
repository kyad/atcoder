#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  int len = 0;
  int prev = -1;
  int ans = -1;
  for (int i = 0; i < N; i++) {
    if (len >= 1) {
      if (abs(prev - A.at(i)) > K) {
        len = 1;
        prev = A.at(i);
        ans = max(len, ans);
        continue;
      }
    }
    prev = A.at(i);
    len++;
    ans = max(len, ans);
  }
  cout << ans << '\n';
  return 0;
}
