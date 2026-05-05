#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N, M, K;
  cin >> N >> M >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    long long now = A.at(i) / K;
    sum += now;
  }
  bool ans = M <= sum;
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
