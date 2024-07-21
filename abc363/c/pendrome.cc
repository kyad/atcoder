#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool is_pendrome(string &S) {
  const int N = S.size();
  for (int i = 0; i < N / 2; i++) {
    const int j = N - 1 - i;
    if (S.at(i) != S.at(j)) {
      return false;
    }
  }
  return true;
}

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  auto f = [&](string &T) -> bool {
    for (int i = 0; i <= N - K; i++) {
      string now = T.substr(i, K);
      if (is_pendrome(now)) {
        return false;
      }
    }
    return true;
  };

  vector<int> P(N, -1);
  for (int i = 0; i < N; i++) {
    P.at(i) = i;
  }
  set<string> st;
  do {
    string T;  // 今の文字列
    for (int i = 0; i < N; i++) {
      int p = P.at(i);
      T.push_back(S.at(p));
    }
    if (f(T)) {
      st.insert(T);
    }
  } while (next_permutation(P.begin(), P.end()));

  int ans = st.size();
  cout << ans << endl;
  return 0;
}
