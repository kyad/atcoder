#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N), B(N), D(N);
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
    D.at(i) = A.at(i) - B.at(i);
    sum += A.at(i);
  }
  sort(D.begin(), D.end());
  for (int i = 0; i < K; i++) {
    int ii = N - 1 - i;
    sum -= D.at(ii);
  }
  cout << sum << '\n';
  return 0;
}
