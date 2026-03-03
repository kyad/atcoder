#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<int> U(M), V(M);
  vector<long long> B(M);
  for (int j = 0; j < M; j++) {
    cin >> U.at(j) >> V.at(j) >> B.at(j);
    U.at(j)--;
    V.at(j)--;
  }
  const long long INF = 4e18;
  long long ans = -INF;
  // next_combination(N, K)
  vector<int> mask(N, 1);
  for (int i = 0; i < N - K; i++) {
    mask.at(i) = 0;
  }
  do {
    long long now = 0;
    for (int i = 0; i < N; i++) {
      if (mask.at(i)) {
        // Do something
        now += A.at(i);
      }
    }
    for (int j = 0; j < M; j++) {
      if (mask.at(U.at(j)) && mask.at(V.at(j))) {
        now -= B.at(j);
      }
    }
    ans = max(ans, now);
  } while (next_permutation(mask.begin(), mask.end()));
  cout << ans << '\n';
  return 0;
}
