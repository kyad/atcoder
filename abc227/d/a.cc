// https://atcoder.jp/contests/abc227/tasks/abc227_d

#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  long long left = 0;  // OK
  long long right = (1000000000000 * N + 1) / K + 1;  //NG
  while (right - left > 1) {
    long long P = (left + right) / 2;
    long long sum = 0;
    for (int n = 0; n < N; n++) {
      sum += min(A.at(n), P);
    }
    if (sum >= P * K) {  // OK
      left = P;
    } else {
      right = P;
    }
  }
  cout << left << endl;
  return 0;
}
