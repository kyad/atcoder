#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long kadane(vector<long long> &A) {
  int N = A.size();
  vector<long long> mx(N, 0);
  long long now = 0;
  for (int i = 0; i < N; i++) {
    now += A.at(i);
    mx.at(i) = max(now, A.at(i));
    now = mx.at(i);
  }
  long long ans = *max_element(mx.begin(), mx.end());
  return ans;
}

int main() {
  int N;
  long long C;
  cin >> N >> C;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  long long sumA = 0;
  for (int i = 0; i < N; i++) {
    sumA += A.at(i);
  }

  // C <= 0の時の処理
  bool Cpos = true;
  if (C <= 0) {
    Cpos = false;
    C *= -1;
    for (int i = 0; i < N; i++) {
      A.at(i) *= -1;
    }
  }
  long long k = kadane(A);
  // C <= 0の時の処理を戻す
  if (!Cpos) {
    k *= -1;
    C *= -1;
  }

  long long res = sumA - k;
  long long now = res + k * C;
  long long ans = max(sumA, now);
  cout << ans << endl;
  return 0;
}
