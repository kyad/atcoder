#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long T;
  cin >> N >> T;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  long long S = 0;
  for (int n = 0; n < N; n++) {
    S += A.at(n);
  }
  T %= S;
  for (int i = 0; i < N; i++) {
    if (T < A[i]) {
      cout << (i + 1) << " " << T << endl;
      return 0;
    } else {
      T -= A[i];
    }
  }
  return -1;
}
