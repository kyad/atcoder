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
  int ans = 0;
  if (A.at(0) == K) {
    ans++;
  }
  for (int i = 1; i < N; i++) {
    int a = A.at(i - 1);
    int b = A.at(i);
    if (a > K && b < K) {
      ans++;
    } else if (a < K && b > K) {
      ans++;
    } else if (b == K) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
