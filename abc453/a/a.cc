#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S, ans;
  cin >> S;
  bool leading_o = true;
  for (int i = 0; i < N; i++) {
    if (leading_o && S.at(i) == 'o') {
    } else {
      leading_o = false;
      ans.push_back(S.at(i));
    }
  }
  cout << ans << '\n';
  return 0;
}
