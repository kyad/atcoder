#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<int> count(string S) {
  int N = S.size();
  vector<int> ans(26, 0);
  for (int n = 0; n < N; n++) {
    if (S[n] == '@') {
      continue;
    }
    ans[S[n] - 'a']++;
  }
  return ans;
}

int count_at(string S) {
  int ans = 0;
  for (char c : S) {
    if (c == '@') {
      ans++;
    }
  }
  return ans;
}

// Tの@をおきかえてSにあわせられるか？
bool solve(string S, string T) {
  vector<int> s = count(S);
  vector<int> t = count(T);
  int at_s = count_at(S);
  int at_t = count_at(T);
  for (int i = 0; i < 26; i++) {
    char c = 'a' + i;
    if (c == 'a' || c == 't' || c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'r') {
      if (s[i] < t[i]) {
        at_s -= (t[i] - s[i]);
        if (at_s < 0) {
          return false;
        }
      } else if (s[i] > t[i]) {
        at_t -= (s[i] - t[i]);
        if (at_t < 0) {
          return false;
        }
      }
    } else {  // != atcoder
      if (s[i] != t[i]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  string S;
  cin >> S;
  string T;
  cin >> T;
  bool ans = solve(S, T);
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
