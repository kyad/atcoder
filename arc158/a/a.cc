#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void testcase() {
  vector<long long> X(3);
  long long S = 0;
  for (int i = 0; i < 3; i++) {
    cin >> X.at(i);
    S += X.at(i);
  }
  if (S % 3 != 0) {
    cout << -1 << endl;
    return;
  }
  long long Y = S / 3;
  long long sum = 0;
  for (int i = 0; i < 3; i++) {
    long long Z = abs(Y - X.at(i));
    if (Z % 2 != 0) {
      cout << -1 << endl;
      return;
    }
    sum += (Z / 2);
  }
  if (sum % 2 != 0) {
    cout << -1 << endl;
    return;
  }
  long long ans = sum / 2;
  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
