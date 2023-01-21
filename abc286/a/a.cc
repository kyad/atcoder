#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, P, Q, R, S;
  cin >> N >> P >> Q >> R >> S;
  P--; Q--; R--; S--;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int M = Q - P + 1;
  for (int m = 0; m < M; m++) {
    swap(A.at(P + m), A.at(R + m));
  }
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << (n == N - 1 ? '\n' : ' ');
  }
  return 0;
}
