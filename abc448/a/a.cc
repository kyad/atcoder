#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    if (A.at(i) < X) {
      X = A.at(i);
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
  return 0;
}
