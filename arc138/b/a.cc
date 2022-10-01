// https://atcoder.jp/contests/arc138/tasks/arc138_b

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
  int l = 0;
  int r = N - 1;
  bool ans = false;
  while (l <= r) {
    // B^n
    while (l <= r && A[r] == 0) {
      r--;
    }
    if (l > r) {
      ans = true;
      break;
    }
    // A
    if (A[l] != 0) {
      ans = false;
      break;
    }
    l++;
    if (l > r) {
      ans = true;
      break;
    }
    // B^n (1)
    while (l <= r && A[r] == 1) {
      r--;
    }
    if (l > r) {
      ans = true;
      break;
    }
    // A (1)
    if (A[l] != 1) {
      ans = false;
      break;
    }
    l++;
    if (l > r) {
      ans = true;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
