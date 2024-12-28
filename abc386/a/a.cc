#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 4;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  bool ans = false;
  if (A[0] == A[1] && A[2] == A[3]) {
    ans = true;
  } else if (A[0] == A[1] && A[1] == A[2]) {
    ans = true;
  } else if (A[1] == A[2] && A[2] == A[3]) {
    ans = true;
  }
  if (A[0] == A[1] && A[1] == A[2] && A[2] == A[3]) {
    ans = false;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
