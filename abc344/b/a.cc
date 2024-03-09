#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> A(101);
  int N = 0;
  for (int n = 0; n < 100; n++) {
    int a;
    cin >> a;
    A[n] = a;
    N++;
    if (a == 0) {
      break;
    }
  }
  for (int n = N - 1; n >= 0; n--) {
    cout << A[n] << endl;
  }
  return 0;
}
