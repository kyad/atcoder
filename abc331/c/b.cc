#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int M = *max_element(A.begin(), A.end());  // Aの最大値
  vector<int> cnt(M + 1, 0);  // cnt[a]: Aiの中で値がaの個数 (0<=a<=M)
  for (int i = 0; i < N; i++) {
    cnt[A[i]]++;
  }
  vector<long long> B(M + 1, 0);  // B[a]: aより大きな要素全ての和 (0<=a<=M)
  for (int a = M - 1; a >= 0; a--) {
    B[a] = B[a + 1] + (long long)(a + 1) * cnt[a + 1];
  }

  // 答えを出力
  for (int i = 0; i < N; i++) {
    cout << B[A[i]] << (i + 1 == N ? '\n' : ' ');
  }
  return 0;
}
