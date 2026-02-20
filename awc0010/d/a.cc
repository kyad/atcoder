#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  sort(H.begin(), H.end());
  reverse(H.begin(), H.end());
  long long ans = 0;
  for (int i = 0; i < K; i++) {
    ans++;
  }
  for (int i = K; i < N; i++) {
    ans += H.at(i);
  }
  cout << ans << '\n';
  return 0;
}
