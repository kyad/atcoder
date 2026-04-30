#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i <= N - 2; i++) {
    if (A.at(i) < 0 || A.at(i + 1) < 0) {
      continue;
    }
    if (A.at(i) == A.at(i + 1)) {
    } else if (A.at(i) > A.at(i + 1)) {
      A.at(i) += A.at(i + 1) / 2;
      A.at(i + 1) = -1;
    } else {
      A.at(i + 1) += A.at(i) / 2;
      A.at(i) = -1;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) > 0) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
