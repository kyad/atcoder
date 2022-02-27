// https://atcoder.jp/contests/abc241/tasks/abc241_e

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  long long X = 0;
  // 前回、余りrになった時のkとX
  vector<long long> dp_k(N, -1);
  vector<long long> dp_X(N, -1);
  int r = 0;
  bool detect_loop = false;
  for (long long k = 0; k < K; k++) {
    X += A[r];
    r = X % N;  // next
    if (detect_loop == false && dp_k[r] >= 0) {
      detect_loop = true;
      long long dk = k - dp_k[r];
      long long dX = X - dp_X[r];
      long long count = (K - k - 1) / dk;
      k += dk * count;
      X += dX * count;
    } else {
      dp_k[r] = k;
      dp_X[r] = X;
    }
  }
  cout << X << endl;
  return 0;
}
