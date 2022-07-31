// https://atcoder.jp/contests/arc144/tasks/arc144_c

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    A.at(n) = n + 1;
  }
  do {
    bool ok = true;
    for (int n = 0; n < N; n++) {
      if (abs(A.at(n) - (n + 1)) < K) {
        ok = false;
      }
    }
    if (!ok) continue;
    for (int n = 0; n < N; n++) {
      cout << A.at(n) << (n == N - 1 ? '\n' : ' ');
    }
    return 0;
  } while (next_permutation(A.begin(), A.end()));
  cout << -1 << endl;
  return 0;
}
