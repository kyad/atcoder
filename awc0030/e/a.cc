// https://atcoder.jp/contests/awc0030/editorial/17729

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  int M = 1000000;
  vector<int> C(M + 1, 0);
  for (int i = 0; i < N; i++) {
    C.at(A.at(i))++;
  }
  vector<long long> D(M + 1, 0);
  for (int g = 1; g <= M; g++) {
    for (int h = g; h <= M; h += g) {
      D.at(g) += C.at(h);
    }
  }
  long long ans = -1;
  for (int g = 1; g <= M; g++) {
    long long now = D.at(g) * g;
    ans = max(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
