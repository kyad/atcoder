#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool is_palindrome(string S) {
  int N = S.size();
  for (int l = 0; l < N / 2; l++) {
    int r = N - 1 - l;
    if (S.at(l) != S.at(r)) {
      return false;
    }
  }
  return true;
}

int main() {
  string S;
  cin >> S;
  int ans = 0;
  int N = S.size();
  for (int i = 0; i < N; i++) {
    for (int len = 1; len <= N - i; len++) {
      string T = S.substr(i, len);
      if (is_palindrome(T)) {
        ans = max(ans, len);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
