#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    cin >> B.at(i);
  }
  vector<long long> C(N);
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    C.at(i) = B.at(i) - A.at(i);
    sum += A.at(i);
  }
  sort(C.begin(), C.end());
  reverse(C.begin(), C.end());
  for (int i = 0; i < K; i++) {
    sum += C.at(i);
  }
  cout << sum << '\n';
  return 0;
}
