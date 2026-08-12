#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  long long K;
  cin >> N >> M >> K;
  vector<long long> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T.at(i);
  }
  for (int j = 0; j < M; j++) {
    int D;
    cin >> D;
    D--;
    T.at(D) = 0;
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long now = T.at(i) / K;
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
