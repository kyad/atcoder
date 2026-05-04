#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> S(N), C(N - 1);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  for (int i = 0; i < N - 1; i++) {
    cin >> C.at(i);
  }
  long long ans = S.at(0);
  long long now = S.at(0);
  for (int i = 0; i < N - 1; i++) {
    now -= C.at(i);
    now += S.at(i + 1);
    ans = max(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
