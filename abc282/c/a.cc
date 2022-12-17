#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  string ans;
  int replace = 1;
  for (int n = 0; n < N; n++) {
    if (S[n] == '"') {
      replace = 1 - replace;
      ans += '"';
    } else if (S[n] == ',') {
      if (replace) {
        ans += '.';
      } else {
        ans += ',';
      }
    } else {
      ans += S[n];
    }
  }
  cout << ans << endl;
  return 0;
}
