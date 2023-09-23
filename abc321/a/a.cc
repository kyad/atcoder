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
  int now = S[0] - '0';
  for (int n = 1; n < N; n++) {
    if (now >= 1 && S[n] - '0' <= now - 1) {
      now = S[n] - '0';
    } else {
      ans = false;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
