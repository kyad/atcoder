#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<long long> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  for (int i = 0; i < N; i++) {
    if (H.at(i) < K) {
      H.at(i) = 0;
    }
  }
  long long sum = 0;
  for (int i = 0; i < M; i++) {
    sum += H.at(i);
  }
  long long ans = sum;
  for (int l = 1; l + M - 1 <= N - 1; l++) {
    int r = l + M - 1;
    sum -= H.at(l - 1);
    sum += H.at(r);
    ans = max(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}
