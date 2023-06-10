#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  char p, q;
  cin >> p >> q;
  int P = p - 'A';
  int Q = q - 'A';
  int A[8] = {0, 3, 1, 4, 1, 5, 9};
  for (int i = 1; i < 8; i++) {
    A[i] += A[i - 1];
  }
  if (P > Q) {
    swap(P, Q);
  }
  int ans = A[Q] - A[P];
  cout << ans << endl;
  return 0;
}
