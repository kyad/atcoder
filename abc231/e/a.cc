// https://atcoder.jp/contests/abc231/tasks/abc231_e

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N;
vector<long long> A;
map<long long, long long> memo;

int calc_idx(long long X) {
  int k;
  for (k = 1; k < N; k++) {
    if (X % A[k + 1] != 0) {
      break;
    }
  }
  return k;
}

long long f(long long X) {
  if (memo.count(X) > 0) {
    return memo[X];
  }
  int k = calc_idx(X);
  long long ans;
  if (k == N) {
    ans = X / A[N];
  } else {
    ans = min(f(X / A[k + 1] * A[k + 1]) + (X % A[k + 1]) / A[k],
              f((X / A[k + 1] + 1) * A[k + 1]) + ((X / A[k + 1] + 1) * A[k + 1] - X) / A[k]);
  }
  return memo[X] = ans;
}

int main() {
  long long X;
  cin >> N >> X;
  A.assign(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  long long ans = f(X);
  cout << ans << endl;
  return 0;
}
