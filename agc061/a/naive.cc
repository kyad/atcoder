#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void shuffle(vector<long long> &A, int L, int R) {
  if (R == L + 1) {
    swap(A[R], A[L]);
    return;
  }
  shuffle(A, L, R - 1);
  shuffle(A, L + 1, R);
}

void testcase() {
  //long long N, K;
  //cin >> N >> K;
  for (int N = 2; N <= 16; N++) {
    vector<long long> A(N + 1, 0);
    for (int i = 1; i <= N; i++) {
      A[i] = i;
    }
    shuffle(A, 1, N);
    //print(N, A);
  }
}

int main() {
  int T;
  //cin >> T;
  T = 1;
  for (int t = 0; t < T; t++) {
    testcase();
  }
  return 0;
}
