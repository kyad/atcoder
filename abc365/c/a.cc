#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long M;
  cin >> N >> M;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  auto f = [&](long long x) -> bool {
    long long sum = 0;
    for (int i = 0; i < N; i++) {
      sum += min(x, A.at(i));
    }
    return sum <= M;
  };
  long long left = 0;  // OK
  long long right = M + 1;  // NG
  while (right - left > 1) {
    long long mid = (left + right) / 2;
    if (f(mid)) {  // OK
      left = mid;
    } else {
      right = mid;
    }
  }
  long long maxA = *max_element(A.begin(), A.end());
  if (maxA <= left) {
    cout << "infinite" << endl;
  } else {
    cout << left << endl;
  }
  return 0;
}
