#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  K--;
  vector<vector<int>> A(N);
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
    for (int j = 0; j < L.at(i); j++) {
      int a;
      cin >> a;
      A.at(i).push_back(a);
    }
  }
  vector<long long> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
  }
  for (int i = 0; i < N; i++) {
    if (K < C.at(i) * L.at(i)) {
      K %= L.at(i);
      int ans = A.at(i).at(K);
      cout << ans << '\n';
      return 0;
    } else {
      K -= C.at(i) * L.at(i);
    }
  }
  assert(false);
  return 0;
}
