#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> A(3);
  for (int i = 0; i < 3; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < 3; i++) {
    if (A[i] * A[(i + 1) % 3] == A[(i + 2) % 3]) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
