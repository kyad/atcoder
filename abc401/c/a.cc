#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N + 1, 0), S(N + 1, 0);
  const long long M = 1000000000;
  // 初期値
  for (int i = 0; i < K; i++) {
    if (i > N) {
      break;
    }
    A.at(i) = 1;
    S.at(i) = i + 1;
  }
  for (int i = K; i <= N; i++) {
    if (i - K - 1 >= 0) {
      A.at(i) = (S.at(i - 1) - S.at(i - K - 1) + M) % M;
    } else {
      A.at(i) = S.at(i - 1);
    }
    S.at(i) = (S.at(i - 1) + A.at(i)) % M;
  }
  
  long long ans = A.at(N);
  cout << ans << endl;
  return 0;
}
