#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  vector<int> T(N);
  for (int n = 0; n < N; n++) {
    cin >> T.at(n);
  }
  for (int n = 1; n < N; n++) {
    if (T[n] - T[n - 1] <= D) {
      cout << T[n] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
