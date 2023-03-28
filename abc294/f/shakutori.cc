#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  long long K;
  cin >> N >> M >> K;
  vector<double> A(N), B(N);
  for (int n = 0; n < N; n++) {
    double b;
    cin >> A.at(n) >> b;
    B.at(n) = A.at(n) + b;
  }
  vector<double> C(M), D(M);
  for (int m = 0; m < M; m++) {
    double d;
    cin >> C.at(m) >> d;
    D.at(m) = C.at(m) + d;
  }
  auto f = [&N, &M, &A, &B, &C, &D](double X) -> long long {
    vector<double> L(N);
    for (int n = 0; n < N; n++) {
      L.at(n) = A[n] - X * B[n];
    }
    vector<double> R(M);
    for (int m = 0; m < M; m++) {
      R.at(m) = - (C[m] - X * D[m]);
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    long long ans = 0;
    int l = 0;
    for (int m = 0; m < M; m++) {
      while (l < N && R[m] > L[l]) {
        l++;
      }
      ans += (N - l);
    }
    return ans;
  };
  double left = 0;  // OK
  double right = 1;  // NG
  for (int i = 0; i < 40; i++) {
    double mid = (left + right) / 2;
    if (f(mid) >= K) {  // OK
      left = mid;
    } else {  // NG
      right = mid;
    }
  }
  printf("%.10lf\n", left * 100);
  return 0;
}
