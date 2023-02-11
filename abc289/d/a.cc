#include <cassert>
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
  int M;
  cin >> M;
  vector<int> B(M);
  for (int m = 0; m < M; m++) {
    cin >> B.at(m);
  }
  int X;
  cin >> X;
  vector<bool> mochi(X + 1, false);
  for (int m = 0; m < M; m++) {
    mochi[B.at(m)] = true;
  }
  vector<int> memo(X + 1, -1);
  memo[0] = 1;
  auto f = [&](auto f, int x) -> int {
    if (memo[x] >= 0) {
      return memo[x];
    }
    int ans = 0;
    for (int n = 0; n < N; n++) {
      int nx = x - A[n];
      if (nx < 0) {
        continue;
      }
      if (mochi[nx]) {
        continue;
      }
      int now = f(f, nx);
      if (now == 1) {
        ans = 1;
        break;
      }
    }
    return memo[x] = ans;
  };
  int ans = f(f, X);
  if (ans == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
