// https://atcoder.jp/contests/arc146/tasks/arc146_b

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// A以上かつXの上位集合の最小の数Bを返す
unsigned int upper(unsigned int A, unsigned int X) {
  unsigned int B = X;
  for (int j = 30; j >= 0; j--) {
    if ((B>>j)&1) {
      continue;
    }
    unsigned int temp = B;
    for (int k = 0; k <= j - 1; k++) {
      temp |= (1<<k);
    }
    if (temp < A) {
      B |= (1<<j);
    }
  }
  return B;
}

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<unsigned int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  unsigned int ans = 0;
  for (int i = 30; i >= 0; i--) {
    unsigned int X = ans + (1<<i);
    vector<unsigned int> diff(N);
    for (int j = 0; j < N; j++) {
      unsigned int B = upper(A[j], X);
      diff[j] = B - A[j];
    }
    sort(diff.begin(), diff.end());
    long long sum = 0;
    for (int j = 0; j < K; j++) {
      sum += diff.at(j);
    }
    if (sum <= M) {
      ans |= (1<<i);
    }
  }
  cout << ans << endl;
  return 0;
}
