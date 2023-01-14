#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;



int main() {
  const int INF = 1e9 + 1;
  vector<int> B(900000 + 5, INF);
  int b = 0;
  vector<int> S(6, 0);
  for (int n = 0; n <= 999999; n++) {
    int value = n;
    for (int i = 0; i < 6; i++) {
      S[i] = value % 10;
      value /= 10;
    }
    // 001233454
    int M
      = S[0] * 100000000
      + S[0] * 10000000
      + S[1] * 1000000
      + S[2] * 100000
      + S[3] * 10000
      + S[3] * 1000
      + S[4] * 100
      + S[5] * 10
      + S[4] * 1;
    if (M < 100000000) {
      continue;
    }
    B[b] = M;
    b++;
  }
  sort(B.begin(), B.end());
  int N;
  cin >> N;
  cout << B.at(N - 1) << endl;
  return 0;
}
