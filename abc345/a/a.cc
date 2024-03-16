#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  bool ans = true;
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      if (S[i] != '<') {
        ans = false;
      }
    } else if (i == N - 1) {
      if (S[i] != '>') {
        ans = false;
      }
    } else {
      if (S[i] != '=') {
        ans = false;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
