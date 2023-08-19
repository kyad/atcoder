#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int M;
  cin >> M;
  vector<int> D(M);
  int sum = 0;
  for (int m = 0; m < M; m++) {
    cin >> D.at(m);
    sum += D.at(m);
  }
  int d = sum / 2;
  for (int m = 0; m < M; m++) {
    if (d < D[m]) {
      int a = m + 1;
      int b = d + 1;
      cout << a << ' ' << b << endl;
      return 0;
    }
    d -= D[m];
  }
  assert(false);
  return 0;
}
