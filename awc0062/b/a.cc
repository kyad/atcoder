#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  long long G;
  cin >> N >> K >> G;
  vector<long long> D(N), T(N);
  for (int i = 0; i < N; i++) {
    cin >> D.at(i) >> T.at(i);
  }
  long long Tall = 0;
  for (int i = 0; i < N; i++) {
    Tall += T.at(i);
  }
  long long sum = 0;
  for (int i = 0; i < K; i++) {
    sum += T.at(i);
  }
  long long mx = sum;
  for (int l = 0; l <= N - K; l++) {
    mx = max(mx, sum);
    if (l == N - K) {
      break;
    }
    sum -= T.at(l);
    sum += T.at(l + K);
  }
  long long ans = G + Tall - mx;
  cout << ans << '\n';
  return 0;
}
