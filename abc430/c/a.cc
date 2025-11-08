#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  S.insert(S.begin(), '_');
  vector<int> X(N + 1, 0);
  vector<int> Y(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    if (S.at(i) == 'a') {
      X.at(i) = 1;
    } else {
      Y.at(i) = 1;
    }
  }
  for (int i = 1; i <= N; i++) {
    X.at(i) += X.at(i - 1);
    Y.at(i) += Y.at(i - 1);
  }
  long long ans = 0;
  for (int l = 1; l <= N; l++) {
    int p = lower_bound(X.begin(), X.end(), X.at(l - 1) + A) - X.begin();
    int q = lower_bound(Y.begin(), Y.end(), Y.at(l - 1) + B) - Y.begin() - 1;
    if (p <= q) {
      int now = q - p + 1;
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}
