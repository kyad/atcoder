#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  for (int n = 0; n < N; n++) {
    cin >> X.at(n) >> Y.at(n);
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  long long ans = 0;
  int M = N / 2;
  for (int n = 0; n < N; n++) {
    ans += abs(X[n] - X[M]);
    ans += abs(Y[n] - Y[M]);
  }
  cout << ans << endl;
  return 0;
}
