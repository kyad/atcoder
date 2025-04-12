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
  int num_o = count(S.begin(), S.end(), 'o');
  int R = K - num_o;
  // oの前後の?を埋める
  for (int i = 0; i < N; i++) {
    if (S.at(i) == 'o') {
      if (i > 0 && S.at(i - 1) == '?') {
        S.at(i - 1) = '.';
      }
      if (i < N - 1 && S.at(i + 1) == '?') {
        S.at(i + 1) = '.';
      }
    }
  }
  string T(S);
  for (int i = 0; i < N; i++) {
    if (T.at(i) != '?') {
      T.at(i) = 'x';
    }
  }
  int F = 0;
  for (auto [l, c] : runlength(T)) {
    if (c == 'x') {
      continue;
    }
    int now = (l + 1) / 2;
    F += now;
  }
  if (F == R) {
    int i = 0;
    for (auto [l, c] : runlength(T)) {
      if (c == 'x') {
        i += l;
        continue;
      }
      if (l % 2 == 0) {
        i += l;
        continue;
      }
      for (int j = 0; j < l; j++) {
        if (j % 2 == 0) {
          S.at(i) = 'o';
        } else {
          S.at(i) = '.';
        }
        i++;
      }
    }
  } else if (R == 0) {
    for (int i = 0; i < N; i++) {
      if (S.at(i) == '?') {
        S.at(i) = '.';
      }
    }
  }
  cout << S << endl;
  return 0;
}
