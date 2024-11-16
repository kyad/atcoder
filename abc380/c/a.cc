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
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  vector<pair<int, char> > run = runlength(S);
  int a;
  if (run.at(0).second == '0') {
    a = 2 * K - 1;
  } else {
    a = 2 * K - 2;
  }
  int b = a - 1;
  swap(run.at(a), run.at(b));
  string ans;
  for (auto [len, c] : run) {
    for (int i = 0; i < len; i++) {
      ans.push_back(c);
    }
  }
  cout << ans << endl;
  return 0;
}
