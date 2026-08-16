#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  
  // 桁数が大きい順、桁数が同じなら文字列が大きい順に並べる
  vector<pair<int, string>> A;
  for (int i = 0; i < N; i++) {
    A.push_back(make_pair(S.at(i).size(), S.at(i)));
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());

  // K個目以降で数値として最大のものを選ぶ
  long long best = 0;
  for (int i = K - 1; i < N; i++) {
    best = max(best, stoll(A.at(i).second));
  }

  string ans = "0";
  auto test = [&](vector<string> S) {
    sort(S.begin(), S.end(), [](const string &a, const string &b){
      return a + b > b + a;
    });
    string T = "";
    for (string s: S) {
      T += s;
    }

    // Leading zeroを消す
    string now;
    bool leading_zero = true;
    for (char c : T) {
      if (leading_zero && c == '0') {
        continue;
      }
      leading_zero = false;
      now.push_back(c);
    }

    // ansとnowを比較
    if (now.size() > ans.size()) {
      ans = now;
    } else if (now.size() == ans.size()) {
      if (now > ans) {
        ans = now;
      }
    }
    
  };

  vector<string> T(K);
  for (int i = 0; i < K; i++) {
    T.at(i) = A.at(i).second;
  }
  test(T);

  vector<string> U(K);
  for (int i = 0; i < K - 1; i++) {
    U.at(i) = A.at(i).second;
  }
  U.at(K - 1) = to_string(best);
  test(U);

  cout << ans << '\n';
  return 0;
}
