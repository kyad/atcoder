// https://atcoder.jp/contests/arc148/tasks/arc148_a

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  int M = A.size() - 1;
  if (M == 0) {
    cout << 1 << endl;
    return 0;
  }
  vector<int> B(M);
  for (int m = 0; m < M; m++) {
    B.at(m) = A.at(m + 1) - A.at(m);
  }
  int g = B[0];
  for (int m = 1; m < M; m++) {
    g = __gcd(g, B[m]);
  }
  cout << (g >= 2 ? 1 : 2) << endl;
  return 0;
}
