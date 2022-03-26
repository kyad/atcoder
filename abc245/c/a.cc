#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }
  bool ans = true;
  bool prev_a_ok = true;
  bool prev_b_ok = true;
  for (int n = 0; n < N; n++) {
    if (n == 0) {
      continue;
    }
    bool next_a_ok = false;
    bool next_b_ok = false;
    if (prev_a_ok) {
      if (abs(A[n - 1] - A[n]) <= K) {
        next_a_ok = true;
      }
      if (abs(A[n - 1] - B[n]) <= K) {
        next_b_ok = true;
      }
    }
    if (prev_b_ok) {
      if (abs(B[n - 1] - A[n]) <= K) {
        next_a_ok = true;
      }
      if (abs(B[n - 1] - B[n]) <= K) {
        next_b_ok = true;
      }
    }
    if (next_a_ok == false && next_b_ok == false) {
      ans = false;
    }
    prev_a_ok = next_a_ok;
    prev_b_ok = next_b_ok;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
