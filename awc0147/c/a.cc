#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, T, K;
  cin >> N >> T >> K;
  vector<int> D(N);
  for (int i = 0; i < N; i++) {
    cin >> D.at(i);
  }
  int N2 = 1<<N;
  vector<int> mask(N);
  int ans = N + 10;
  for (int bit = 0; bit < N2; bit++) {
    // マスクを埋める
    int count = 0;
    for (int i = 0; i < N; i++) {
      if (bit>>i&1) {
        mask.at(i) = 1;
        count++;
      } else {
        mask.at(i) = 0;
      }
    }
    if (count > K) {
      continue;
    }
    // マスクのレンを求める
    vector<int> L, R;  // マスク
    vector<int> P, Q;  // マスクじゃない
    int l = -1;
    int p = -1;
    for (int i = 0; i < N; i++) {
      if (mask.at(i) == 1) {  // マスク
        if (p >= 0) {
          P.push_back(p);
          Q.push_back(i - 1);
        }
        p = -1;
        if (l < 0) {
          l = i;
        }
      } else {  // マスクじゃない
        if (l >= 0) {
          L.push_back(l);
          R.push_back(i - 1);
        }
        l = -1;
        if (p < 0) {
          p = i;  // 左端確定
        }
      }
    }
    if (l >= 0) {
      L.push_back(l);
      R.push_back(N - 1);
    }
    if (p >= 0) {
      P.push_back(p);
      Q.push_back(N - 1);
    }
    int now = 0;
    // 各マスクのレン毎に
    int M = L.size();
    for (int j = 0; j < M; j++) {
      int l = L.at(j);
      int r = R.at(j);
      if (l == 0 || r == N - 1) {
        continue;
      }
      int A = D.at(l - 1);
      int B = D.at(r + 1);
      int k = r - l + 1;
      if (abs(A - B) <= (k + 1) * T) {
      } else {
        now++;
      }
    }
    // 各非マスクのレン毎に
    int S = P.size();
    for (int j = 0; j < S; j++) {
      int p = P.at(j);
      int q = Q.at(j);
      for (int i = p; i <= q - 1; i++) {
        if (abs(D.at(i) - D.at(i + 1)) > T) {
          now++;
        }
      }
    }
    ans = min(ans, now);
  }
  cout << ans << '\n';
  return 0;
}
