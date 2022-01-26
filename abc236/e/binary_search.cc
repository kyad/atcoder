// https://atcoder.jp/contests/abc236/tasks/abc236_e

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void solve_average(vector<int>& A) {
  size_t N = A.size();
  double left = 1;  // OK
  double right = 1e9+1;  // NG
  for (int i = 0; i < int(13. * log(10) / log(2)) + 1; i++) {
    double mid = (left + right) / 2.;
    vector<double> B(N);
    for (size_t n = 0; n < N; n++) {
      B.at(n) = (double)A.at(n) - mid;
    }
    double dp0 = 0;
    double dp1 = 0;
    for (size_t n = 0; n < N; n++) {
      double dp0_next = dp1;
      double dp1_next = max(dp0, dp1) + B.at(n);
      dp0 = dp0_next;
      dp1 = dp1_next;
    }
    if (max(dp0, dp1) >= 0) {
      left = mid;
    } else {
      right = mid;
    }
  }
  double mid = (left + right) / 2.;
  cout << mid << endl;
}

void solve_median(vector<int>& A) {
  size_t N = A.size();
  int left = 1;  // OK
  int right = 1000000000 + 1;  // NG
  while (right - left > 1) {
    int mid = (left + right) / 2;
#if 1
    // AC
    int ge = 0;  // # of >= mid
    int lt = 0;  // # of < mid
    int interval = 0;
    for (size_t n = 0; n < N; n++) {
      if (A.at(n) >= mid) {
        ge++;
        lt += interval / 2;
        interval = 0;
      } else {
        interval++;
      }
    }
    lt += interval / 2;
    if (ge > lt) {  // OK
      left = mid;
    } else {  // NG
      right = mid;
    }
#else
    // AC
    vector<int> B(N);
    for (size_t n = 0; n < N; n++) {
      B.at(n) = A.at(n) >= mid ? 1 : -1;
    }
    int dp0 = 0;
    int dp1 = 0;
    for (size_t n = 0; n < N; n++) {
      int dp0_next = dp1;
      int dp1_next = max(dp0, dp1) + B.at(n);
      dp0 = dp0_next;
      dp1 = dp1_next;
    }
    if (max(dp0, dp1) > 0) {
      left = mid;
    } else {
      right = mid;
    }
#endif
  }
  cout << left << endl;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  solve_average(A);
  solve_median(A);
  return 0;
}
