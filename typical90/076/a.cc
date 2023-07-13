#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  long long sum = accumulate(A.begin(), A.end(), 0LL);
  vector<long long> B(N * 2 + 1, 0);
  for (int n = 0; n < N; n++) {
    B.at(n + 1) = A.at(n);
    B.at(n + 1 + N) = A.at(n);
  }
  vector<long long> S(N * 2 + 1, 0);
  for (int n = 1; n < N * 2 + 1; n++) {
    S[n] = B[n] + S[n - 1];
  }
  for (int i = 1; i <= N; i++) {
    const int j = i + N - 1;
    int left = i;  // OK
    int right = j;  // NG
    while (right - left > 1) {
      int mid = (left + right) / 2;
      long long now = (S.at(mid) - S.at(i - 1)) * 10;
      if (now <= sum) {
        left = mid;  // OK
      } else {
        right = mid;  // NG
      }
    }
    long long now = (S.at(left) - S.at(i - 1)) * 10;
    if (now == sum) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
