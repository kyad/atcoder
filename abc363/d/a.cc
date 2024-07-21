// https://atcoder.jp/contests/abc363/editorial/10464

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 4e18+10;

bool is_pendrome(string &S) {
  string T(S);
  reverse(T.begin(), T.end());
  return S == T;
}

string naive(long long N) {
  int count = 0;
  int i = 0;
  while (true) {
    string s = to_string(i);
    if (is_pendrome(s)) {
      if (count >= N) {
        break;
      }
      count++;
    }
    i++;
  }
  return to_string(i);
}

template<class T> T ceildiv(T a, T b);
// floor(a / b)を計算する。aが負の場合は負の無限大へ丸める。
template<class T> T floordiv(T a, T b) { assert(b > 0); return (a >= 0) ? (a / b) : (-ceildiv(-a, b)); }
// ceil(a / b)を計算する。aが負の場合は正の無限大へ丸める。
template<class T> T ceildiv(T a, T b) { assert(b > 0); return (a >= 0) ? ((a + b - 1) / b) : (-floordiv(-a, b)); }

long long TEN(int x) {
  if (x == 0) {
    return 1LL;
  } else {
    return TEN(x - 1) * 10LL;
  }
}

int main() {
  long long N;
  cin >> N;
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  // 以降は、1以上の回文数を考える。
  N--;  // 回文数0を除く
  // A, B
  vector<long long> A, B;
  {
    A.push_back(0);  // A[0]
    B.push_back(A.at(0));  // B[0]
    long long sum = B.at(0);
    long long count = 9;
    for (int i = 1; i <= 36; i++) {
      if (i >= 3 && i % 2 == 1) {
        count *= 10LL;
      }
      sum += count;
      A.push_back(count);
      B.push_back(sum);
      if (sum > INF) {
        break;
      }
    }
  }
  // 回文数の桁数dを求める
  int d = 0;
  for (d = 0;; d++) {
    if (N <= B.at(d)) {
      break;
    }
  }
  // 回文数の左半分Lを求める
  int x = ceildiv(d, 2);
  long long shift = (long long)N - B.at(d - 1) - 1LL;
  long long L = TEN(x - 1) + shift;
  // 答を求める
  string ans = to_string(L);
  string rL = to_string(L);
  reverse(rL.begin(), rL.end());
  if (d % 2) {
    ans += rL.substr(1, rL.size() - 1);
  } else {
    ans += rL;
  }
  //string ans = naive(N - 1);
  cout << ans << endl;
  return 0;
}
