#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool check0(vector<int> A, vector<int> D) {
  bool ans = false;
  if (A[0] <= A[1] && A[1] < D[0]) {
    ans = true;
  }
  if (A[0] < D[1] && D[1] <= D[0]) {
    ans = true;
  }
  return ans;
}

bool check(vector<int> A, vector<int> D) {
  bool ans = false;
  if (A[0] == A[1]) {
    ans = true;
  } else if (A[0] < A[1]) {
    if (A[1] < D[0]) {
      ans = true;
    }
  } else {
    if (A[0] < D[1]) {
      ans = true;
    }
  }
  return ans;
}

int main() {
  vector<int> A(2), B(2), C(2), D(2), E(2), F(2);
  for (int i = 0; i < 2; i++) {
    cin >> A.at(i) >> B.at(i) >> C.at(i) >> D.at(i) >> E.at(i) >> F.at(i);
  }
  bool x = check(A, D);
  bool y = check(B, E);
  bool z = check(C, F);
  bool ans = false;
  if (x && y && z) {
    ans = true;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
