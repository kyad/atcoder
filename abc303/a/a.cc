#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool f(char s, char t) {
  if (s == t) {
    return true;
  }
  if (s == '1' && t == 'l') {
    return true;
  }
  if (s == 'l' && t == '1') {
    return true;
  }
  if (s == '0' && t == 'o') {
    return true;
  }
  if (s == 'o' && t == '0') {
    return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;
  string S, T;
  cin >> S >> T;
  bool ans = true;
  for (int n = 0; n < N; n++) {
    int s = S[n];
    int t = T[n];
    if (f(s, t)) {
      continue;
    }
    ans = false;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
