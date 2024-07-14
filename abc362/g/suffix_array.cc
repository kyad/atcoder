// https://www.youtube.com/live/AsTnBXWeqsE?t=10209s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <atcoder/string>
using namespace atcoder;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int Q;
  cin >> Q;
  vector<int> sa = suffix_array(S);
  // saの中で、T以上の最小の添字を返す(0以上N以下)
  auto upper_bound = [&](string T) -> int {
    int right = N;  // OK
    int left = -1;  // NG
    while (right - left > 1) {
      assert(left + right >= 0);
      int mid = (left + right) / 2;
      int len = T.size() + 1;
      len = min(len, N - sa[mid]);
      if (T <= S.substr(sa[mid], len)) {  // OK
        right = mid;
      } else {
        left = mid;
      }
    }
    return right;
  };
  for (int q = 0; q < Q; q++) {
    string T;
    cin >> T;
    int u = upper_bound(T + '~');
    int l = upper_bound(T);
    int ans = u - l;
    cout << ans << '\n';
  }
  return 0;
}
