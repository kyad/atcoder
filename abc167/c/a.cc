#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  long long X;
  cin >> N >> M >> X;
  vector<long long> C(N);
  vector<vector<long long> > A(N, vector<long long>(M));
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  int N2 = 1<<N;  // 2^N
  const long long INF = 4e18;
  long long ans = INF;
  // ビット全探索
  // bitの下からi桁目(i=0,1, ..., N-1)が1ならi番目の参考書を購入したことにする
  for (int bit = 0; bit < N2; bit++) {
    vector<long long> U(M, 0);  // U[j]: j番目のアルゴリズムの理解度
    long long now = 0; // 書籍費用
    for (int i = 0; i < N; i++) {
      if (bit>>i&1) { // i番目の参考書を購入した時
        now += C[i];
        for (int j = 0; j < M; j++) {
          U[j] += A[i][j];
        }
      }
    }
    // 理解度の確認
    bool ok = true;
    for (int j = 0; j < M; j++) {
      if (U[j] < X) {
        ok = false;
      }
    }
    if (ok) {
      ans = min(ans, now);
    }
  }
  if (ans == INF) {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
