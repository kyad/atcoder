// https://atcoder.jp/contests/abc384/editorial/11568
// https://www.youtube.com/watch?v=634i1jJw024&t=6812s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  const int M = 26;
  // f(Ai+Aj)の()の中身のmod 2^kの同値類を考える
  // d[k]: Ai+Ajが2^kで割り切れるようなものの和
  vector<long long> d(M, 0);
  for (int k = 0; k < M; k++) {
    const int mod = 1<<k;
    vector<int> C(mod, 0);  // C[i]: modで割った余りがiの個数
    vector<long long> S(mod, 0);  // S[i]: modで割った余りがiの総和
    long long now = 0;
    for (int j = 0; j < N; j++) {
      int idx = (mod - A.at(j) % mod) % mod;
      C.at(idx)++;
      S.at(idx) += A.at(j);
      now += S.at(A.at(j) % mod) + (long long)C.at(A.at(j) % mod) * A.at(j);
    }
    d.at(k) = now;
  }
  long long ans = 0;
  for (int k = 0; k <= 24; k++) {
    ans += (d.at(k) - d.at(k + 1)) / (1<<k);
  }
  cout << ans << endl;
  return 0;
}
