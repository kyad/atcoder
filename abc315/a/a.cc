#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  string ans;
  for (char c : S) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      continue;
    }
    ans = ans + c;
  }
  cout << ans << endl;
  return 0;
}
