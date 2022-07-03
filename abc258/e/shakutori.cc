// https://atcoder.jp/contests/abc258/tasks/abc258_e

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  long long X;
  cin >> N >> Q >> X;
  vector<long long> W(N);
  long long W_sum = 0;
  for (int n = 0; n < N; n++) {
    cin >> W.at(n);
    W_sum += W.at(n);
  }
  long long base = X / W_sum;
  // a[p]: じゃがいもnから始めた時に何個入れられるか
  vector<long long> a(N);
  long long na = base * N;
  long long rem = X % W_sum;
  for (int p = 0; p < N; p++) {
    while (rem > 0) {
      rem -= W[(p + na) % N];
      na++;
    }
    a[p] = na;
    rem += W[p];
    na--;
  }
  long long p = 0;  // 今のじゃがいもの番号
  vector<long long> first(N, -1);  // first[p]: 最初にじゃがいもpを入れた回が何回目か
  vector<long long> history(N + 1, -1);  // history[n]: n回目に最初に入れたじゃがいもの番号
  long long start = -1;  // 周期の最初
  long long period = -1;  // 周期
  for (int n = 0; n <= N; n++) {
    if (first[p] >= 0) {  // ループを検出した
      start = first[p];
      period = n - start;
      break;
    }
    first[p] = n;
    history[n] = a[p];
    p = (p + a[p]) % N;
  }
  for (int q = 0; q < Q; q++) {
    long long K;
    cin >> K;
    K--;
    if (K <= start) {
      cout << history[K] << endl;
    } else {
      long long idx = (K - start) % period + start;
      int i = (int)idx;
      cout << history[i] << endl;
    }
  }
  return 0;
}
