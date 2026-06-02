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
  int A, B;
  cin >> A >> B;
  string T;
  cin >> T;
  int cnt = count(T.begin(), T.end(), 'R');
  if (cnt != A) {
    cout << -1 << endl;
    return 0;
  }
  auto run = runlength(T);
  int ans = 0;
  int N = run.size();
  for (int i = 0; i < N; i++) {
    int c = run.at(i).second;
    if (i == 0) {
      continue;
    }
    if (c == 'R') {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
