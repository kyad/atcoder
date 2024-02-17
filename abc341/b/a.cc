#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  long long a = A[0];
  for (int i = 0; i < N - 1; i++) {
    long long S, T;
    cin >> S >> T;
    // i-1から
    long long na = (a / S) * T;
    na += A.at(i + 1);
    a = na;
  }
  cout << a << endl;
  return 0;
}
