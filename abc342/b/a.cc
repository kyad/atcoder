#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> C(N + 1, -1);
  for (int i = 0; i < N; i++) {
    int P;
    cin >> P;
    C.at(P) = i;
  }
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int A, B;
    cin >> A >> B;
    if (C.at(A) < C.at(B)) {
      cout << A << '\n';
    } else {
      cout << B << '\n';
    }
  }
  return 0;
}
