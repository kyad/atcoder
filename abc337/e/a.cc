#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int bitlen(int N) {
  int ans = 0;
  while (N > 0) {
    ans++;
    N /= 2;
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  int M = bitlen(N - 1);
  cout << M << endl;
  // ジュース
  for (int i = 0; i < M; i++) {
    vector<int> A;
    for (int k = 0; k < N; k++) {
      if (k >> i & 1) {
        A.push_back(k);
      }
    }
    int K = A.size();
    assert(K > 0);
    cout << K;
    for (int k: A) {
      cout << ' ' << (k + 1);
    }
    cout << endl;
  }

  // ジャッジ
  string S;
  cin >> S;
  int X = 0;
  for (int i = 0; i < M; i++) {
    if (S.at(i) == '1') {
      X += (1 << i);
    }
  }
  int ans = X + 1;
  cout << ans << endl;
  return 0;
}
