// https://atcoder.jp/contests/abc216/tasks/abc216_e

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  long long left = 0;
  long long right = *max_element(A.begin(), A.end()) + 1;
  long long area = 0;
  while (left < right) {
    long long middle = (right + left) / 2;
    if (left == middle) {
      break;
    }
    area = 0;
    for (int i = 0; i < N; i++) {
      area += max(0LL, A[i] - middle);
    }
    if (area >= K) {
      left = middle;
    } else {
      right = middle;
    }
  }
  area = 0;
  for (int i = 0; i < N; i++) {
    area += max(0LL, A[i] - left);
  }

  long long sum = 0;
  for (int n = 0; n < N; n++) {
    long long temp = max(0LL, A[n] * (A[n] + 1) / 2 - left * (left + 1) / 2);
    sum += temp;
  }
  sum -= (left + 1) * max(0LL, area - K);
  sum = max(0LL, sum);

  cout << sum << endl;
  return 0;
}
