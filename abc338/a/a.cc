#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  bool ans = true;
  int N = S.size();
  if (islower(S[0])) {
    ans = false;
  }
  for (int i = 1; i < N; i++) {
    if (isupper(S[i])) {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
