#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  int L = N + M;
  vector<long long> C(L);
  for (int l = 0; l < L; l++) {
    cin >> C.at(l);
  }
  sort(C.begin(), C.end());
  reverse(C.begin(), C.end());
  long long ans = 0;
  for (int i = 0; i < K; i++) {
    ans += C.at(i);
  }
  cout << ans << '\n';
  return 0;
}
