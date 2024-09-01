#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int M = 32;

bool solve(int H, int W, const vector<int> &cnt) {
  // Wの2進数表現を得る
  vector<long long> res(M, 0);  // res[i]: 2^iに置ける個数
  for (int i = M - 1; i >= 0; i--) {
    if (W>>i&1) {
      long long r = H;
      for (int j = i; j >= 0; j--) {  // 2^jを取れるか確認する
        long long h = r / (1LL<<j);
        r -= h * (1LL<<j);
        long long w = 1LL << (i - j);
        res[j] += h * w;
      }
    }
  }

  for (int i = 31; i >= 0; i--) {
    // aを見たら2^a以上の枠に入れないといけない
    res[i] -= cnt[i];
    if (res[i] < 0) {
      return false;
    }
    if (i >= 1) {
      res[i - 1] += res[i] * 4LL;
    }
  }
  return true;
}


int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> cnt(M, 0);
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    cnt[A]++;
  }
  bool ans = false;
  if (solve(H, W, cnt)) {
    ans = true;
  }
  if (solve(W, H, cnt)) {
    ans = true;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
