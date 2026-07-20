#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  long long S;
  cin >> N >> M >> S;
  long long sumA = 0;
  for (int i = 0; i < N; i++) {
    long long A;
    cin >> A;
    sumA += A;
  }
  long long sumB = 0;
  for (int i = 0; i < M; i++) {
    long long B;
    cin >> B;
    sumB += B;
  }
  if (sumB <= sumA) {
    cout << -1 << endl;
    return 0;
  }
  long long delta = sumB - sumA;
  long long ans = S / delta;
  cout << ans << '\n';
  return 0;
}
