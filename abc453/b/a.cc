#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T, X;
  cin >> T >> X;
  vector<int> ts, as;
  int prev = 0;
  for (int i = 0; i <= T; i++) {
    int A;
    cin >> A;
    if (i == 0) {
      ts.push_back(i);
      as.push_back(A);
      prev = A;
    } else {
      if (abs(prev - A) >= X) {
        ts.push_back(i);
        as.push_back(A);
        prev = A;
      }
    }
  }
  int K = ts.size();
  for (int k = 0; k < K; k++) {
    cout << ts.at(k) << ' ' << as.at(k) << '\n';
  }
  return 0;
}
