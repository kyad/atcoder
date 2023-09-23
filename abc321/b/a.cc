#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N, 0);
  for (int n = 0; n < N - 1; n++) {
    cin >> A.at(n);
  }
  int ans = -1;
  auto judge = [&](vector<int> A) {
    sort(A.begin(), A.end());
    int sum = 0;
    for (int n = 1; n <= N - 2; n++) {
      sum += A[n];
    }
    if (sum >= X) {
      return true;
    } else {
      return false;
    }
  };
  for (int y = 0; y <= 100; y++) {
    A.at(N - 1) = y;
    if (judge(A)) {
      ans = y;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
