#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans = 0;
  for (size_t i = 0; i < S.size(); i++) {
    if (S[i] == 'v') {
      ans++;
    } else {
      ans += 2;
    }
  }
  cout << ans << endl;
  return 0;
}
