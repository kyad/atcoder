#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  const int M = *max_element(A.begin(), A.end());
  vector<long long> cnt(M + 1, 0);
  for (int n = 0; n < N; n++) {
    cnt.at(A.at(n))++;
  }
  vector<long long> sum(M + 1, 0);
  for (int a = M - 1; a >= 1; a--) {
    sum.at(a) = sum.at(a + 1) + cnt.at(a + 1) * (a + 1);
  }
  vector<long long> B(N);
  for (int i = 0; i < N; i++) {
    B.at(i) = sum.at(A.at(i));
  }
  dumpvec(B);
  return 0;
}
