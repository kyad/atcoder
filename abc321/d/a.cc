#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/**
 * AをAの累積和に置き換える。
 * 計算量はO(N)
 */
template<class T> void cumsum(vector<T>& A) {
  int N = A.size();
  for (int i = 1; i < N; i++) {
    A[i] += A[i - 1];
  }
}

int main() {
  int N, M;
  long long P;
  cin >> N >> M >> P;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<long long> B(M);
  for (int m = 0; m < M; m++) {
    cin >> B.at(m);
  }
  sort(B.begin(), B.end());
  vector<long long> sumB(B);
  cumsum(sumB);
  long long L = 0;
  long long U = 0;
  for (int n = 0; n < N; n++) {
    long long x = P - A.at(n);
    int k = lower_bound(B.begin(), B.end(), x) - B.begin();
    assert(0 <= k && k <= M);
    // 上
    int u = M - k;
    long long nowU =  P * u;
    // 下
    long long nowL = 0;
    if (k >= 1) {
      nowL = sumB.at(k - 1);
      nowL += A.at(n) * k;
    }
    U += nowU;
    L += nowL;
  }
  long long ans = U + L;
  cout << ans << endl;
  return 0;
}
