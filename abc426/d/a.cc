#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/**
 * ランレングス符号化
 * 計算量: O(N)
 * \param[in] A: 符号化対象のvector
 * \return vector<pair<int, T> > : 符号化結果
 */
template<class T> vector<pair<int, T> > runlength(vector<T> A) {
  vector<pair<int, T> > ans;
  if (A.empty()) {
    return ans;
  }
  T now = A.at(0);
  int count = 1;
  for (size_t n = 1; n < A.size(); n++) {
    if (now == A.at(n)) {
      count++;
    } else {
      ans.push_back(make_pair(count, now));
      count = 1;
      now = A.at(n);
    }
  }
  if (count > 0) {
    ans.push_back(make_pair(count, now));
  }
  return ans;
}

/**
 * 文字列に対するランレングス符号化
 * 計算量: O(N)
 * \param[in] S: 符号化対象の文字列
 * \return vector<pair<int, char> > : 符号化結果
 */
vector<pair<int, char> > runlength(string S) {
  vector<char> A(S.size());
  for (size_t i = 0; i < S.size(); i++) {
    A.at(i) = S.at(i);
  }
  return runlength(A);
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<pair<int, char> > run = runlength(S);
    vector<int> cnt(2, 0);
    for (int i = 0; i < 2; i++) {
      char c = '0' + i;
      cnt[i] = count(S.begin(), S.end(), c);
    }
    auto f = [&](int a) {
      char d = '0' + a;
      // 最長のレンを求める
      int mx = -1;
      for (auto [len, c] : run) {
        if (c != d) {
          continue;
        }
        if (len > mx) {
          mx = len;
        }
      }
      int ans;
      if (mx == -1) {  // aがまったくなかった時
        ans = N;
      } else {
        ans = (cnt[a] - mx) * 2;
        ans += cnt[1 - a];
      }
      return ans;
    };
    int ans0 = f(0);
    int ans1 = f(1);
    int ans = min(ans0, ans1);
    cout << ans << '\n';
  }
  return 0;
}
