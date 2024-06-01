#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> G(M);
  vector<int> A(M);
  for (int m = 0; m < M; m++) {
    cin >> A.at(m);
  }
  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      int X;
      cin >> X;
      G.at(m) += X;
    }
  }
  bool ans = true;
  for (int m = 0; m < M; m++) {
    if (G.at(m) < A.at(m)) {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
