#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int solve() {
  int N;
  cin >> N;
  string S, T;
  cin >> S;
  cin >> T;
  set<int> xs;
  int a = N + 1;  // 最初に現れる
  int b = -1;  // 最後に現れる
  for (int i = 0; i < N; i++) {
    if (S[i] == 'A' && T[i] == 'B') {
      xs.insert(i);
    } else if (S[i] == 'B' && T[i] == 'A') {
    } else if (S[i] == 'A' && T[i] == 'A') {
      a = min(a, i);
    } else {  // B->B
      b = i;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'A' && T[i] == 'B') {
      // もし前にAがあれば交代する
      if (a < i) {
        // 操作する
        S[i] = 'B';
        ans++;
        continue;
      }
      // 詰み
      return -1;
    } else if (S[i] == 'B' && T[i] == 'A') {
      // もしxがあれば交代する
      if (!xs.empty()) {
        set<int>::iterator jj = xs.upper_bound(i);
        if (jj != xs.end()) {
          int j = *jj;
          // 操作する
          S[i] = 'A';
          S[j] = 'B';
          ans++;
          xs.erase(j);
          // a, bを更新する
          a = min(a, i);
          b = max(b, j);
          continue;
        }
      }
      // もし後にBがあれば交代する
      if (b > i) {
        // 操作する
        S[i] = 'A';
        ans++;
        continue;
      }
      // 詰み
      return -1;
    } else if (S[i] == 'A' && T[i] == 'A') {
    } else {  // B->B
    }
  }
  assert(S == T);
  return ans;
}

int main() {
  int ans = solve();
  cout << ans << endl;
  return 0;
}
