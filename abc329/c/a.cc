#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<long long> count(26, 0);
  char c = S[0];
  long long now = 1;
  for (int n = 1; n < N; n++) {
    if (S[n] == c) {
      now++;
      continue;
    }
    // S[n] != c
    chmax(count[c - 'a'], now);
    c = S[n];
    now = 1;
  }
  // 最後
  chmax(count[c - 'a'], now);

  // ans
  long long ans = 0;
  for (int i = 0; i < 26; i++) {
    ans += count[i];
  }
  cout << ans << endl;
  return 0;
}
