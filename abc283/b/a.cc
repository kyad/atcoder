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
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int k, x;
      cin >> k >> x;
      k--;
      A[k] = x;
    } else {
      int k;
      cin >> k;
      k--;
      cout << A[k] << '\n';
    }
  }
  return 0;
}
