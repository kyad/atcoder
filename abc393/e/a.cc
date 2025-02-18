// https://www.youtube.com/live/RLCWqyDaZU4?t=4876s

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
  const int M = 1e6;
  vector<int> num(M + 1, 0);
  for (int i = 0; i < N; i++) {
    num.at(A.at(i))++;
  }
  // c[j]: Aの要素のうちjの倍数の個数
  vector<int> c(M + 1, 0);
  for (int j = 1; j <= M; j++) {
    for (int k = j; k <= M; k += j) {
      c.at(j) += num.at(k);
    }
  }
  vector<int> B(M + 1, 0);
  for (int j = 1; j <= M; j++) {
    if (c.at(j) < K) {
      continue;
    }
    for (int k = j; k <= M; k += j) {
      B.at(k) = j;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << B.at(A.at(i)) << endl;
  }
  return 0;
}