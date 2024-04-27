#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> A(9);
  for (int n = 0; n < 9; n++) {
    cin >> A.at(n);
  }
  vector<int> B(8);
  for (int n = 0; n < 8; n++) {
    cin >> B.at(n);
  }
  int ans = 0;
  for (int n = 0; n < 9; n++) {
    ans += A[n];
  }
  for (int n = 0; n < 8; n++) {
    ans -= B[n];
  }
  ans++;
  cout << ans << endl;
  return 0;
}
