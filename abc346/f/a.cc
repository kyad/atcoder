#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using lll = __int128;

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
  long long N;
  cin >> N;
  string S;
  cin >> S;
  string T;
  cin >> T;
  // S[c]: cが現れるindeces
  vector<vector<int> > si(26);
  for (size_t i = 0; i < S.size(); i++) {
    char c = S[i];
    si[c - 'a'].push_back(i);
  }
  // Tのランレングス
  vector<pair<int, char> > tr = runlength(T);
  // kでOKか？
  auto f = [&](lll k) -> bool {
    int i = 0;  // 最後に見た文字のインディックス
    lll needed_s = 0;
    if (tr.size() > 0) {
      needed_s++;
    }
    for (size_t j = 0; j < tr.size(); j++) {
      lll len = tr.at(j).first;
      char c = tr.at(j).second;
      int ci = c - 'a';
      lll needed_c = len * k;
      int M = si[ci].size();
      if (M == 0) {
        return false;
      }
      // iより右の個数を除く
      int right = si[ci].end() - lower_bound(si[ci].begin(), si[ci].end(), i);  // iを含めてiより右のcの個数
      int left = M - right;  // iを除いてiより左のcの個数
      lll now = (left + (needed_c - 1)) / M;
      i = si[ci].at((left + (needed_c - 1)) % M);
      needed_s += now;
    }
    if (needed_s <= N) {
      return true;
    } else {
      return false;
    }
  };
  lll left = 0; // OK
  lll right = 5e18; // NG
  while (right - left > 1) {
    lll mid = (left + right) / 2;
    bool now = f(mid);
    if (now) {
      left = mid;
    } else {
      right = mid;
    }
  }
  long long ans = left;
  cout << ans << endl;
  return 0;
}
