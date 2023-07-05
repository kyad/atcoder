#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  sort(A.begin(), A.end());
  bool ans = true;
  int M = N / 2;
  for (int i = 1; i <= M; i++) {
    if (A[i] == A[i + M]) {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
