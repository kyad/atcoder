#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<bool> B(K + 2, false);
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    if (A <= K + 1) {
      B.at(A) = true;
    }
  }
  int k;
  for (k = 0; k < K; k++) {
    if (!B.at(k)) {
      break;
    }
  }
  cout << k << endl;
  return 0;
}
