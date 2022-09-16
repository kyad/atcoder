// https://atcoder.jp/contests/arc148/tasks/arc148_b

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

string S;

string f(int L, int R) {
  string ans(S);
  for (int i = 0; i < R - L + 1; i++) {
    ans[L + i] = (S[R - i] == 'd' ? 'p' : 'd');
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  cin >> S;
  string ans = S;
  int L = -1;
  for (int n = 0; n < N; n++) {
    if (S[n] == 'p') {
      L = n;
      break;
    }
  }
  if (L == -1) {  // ddd...d
    cout << ans << endl;
    return 0;
  }
  // pの最長レンを計算する
  int len = 0;
  int now = 0;
  for (int n = L; n < N; n++) {
    if (S[n] == 'p') {
      now++;
      len = max(len, now);
    } else {
      now = 0;
    }
  }
  // Rの候補を求める
  vector<int> R;
  now = 0;
  for (int n = L; n < N; n++) {
    if (S[n] == 'p') {
      now++;
      if (now == len) {
        R.push_back(n);
      }
    } else {
      now = 0;
    }
  }
  for (size_t i = 0; i < R.size(); i++) {
    ans = min(ans, f(L, R[i]));
  }
  // 追加：一番最初のpのレンを回転した文字列も候補
  {
    int L = -1;
    for (int n = 0; n < N; n++) {
      if (S[n] == 'p') {
        L = n;
        break;
      }
    }
    assert(L >= 0);
    int R = L;
    for (int n = L; n < N; n++) {
      if (S[n] == 'p') {
        R = n;
      } else {
        break;
      }
    }
    ans = min(ans, f(L, R));
  }
  cout << ans << endl;
  return 0;
}
