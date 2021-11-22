// https://atcoder.jp/contests/abc227/tasks/abc227_e

#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Sから転倒数K以下で到達できる文字列の個数を返す
map<pair<string, int>, long long> memo;
long long f(string S, int K) {
  if (K < 0) {
    return 0;
  }
  if (S.empty()){ 
    return 1;
  }
  if (memo.count(make_pair(S, K)) > 0) {
    return memo[make_pair(S, K)];
  }
  long long ans = 0;
  const char key[4] = "KEY";
  for (int k = 0; k < 3; k++) {
    for (int t = 0; t < (int)S.size(); t++) {
      if (S[t] == key[k]) {
        string T = S;
        T.erase(T.begin() + t);
        ans += f(T, K - t);
        break;
      }
    }
  }
  return memo[make_pair(S, K)] = ans;
}

int main() {
  string S;
  int K;
  cin >> S >> K;
  int N = (int)S.size();
  int M = N * (N - 1) / 2;
  K = min(M, K);
  cout << f(S, K) << endl;
  return 0;
}
