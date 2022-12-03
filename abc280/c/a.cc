#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S, T;
  cin >> S;
  cin >> T;
  int ans = 0;
  for (ans = 0; ans < S.size(); ans++) {
    if (S[ans] != T[ans]) {
      break;
    }
  }
  ans++;
  cout << ans << endl;
  return 0;
}
