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
  int L = *A.begin();
  //int R = *A.rbegin();
  for (int i = 1; i <= N - 1; i++) {
    int x = L + i;
    if (A[i] != x) {
      cout << x << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
