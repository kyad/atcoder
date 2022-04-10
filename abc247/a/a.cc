#include <iostream>
using namespace std;

int main() {
  string ans = "0";
  string S;
  cin >> S;
  for (int i = 0; i < 3; i++) {
    ans.push_back(S[i]);
  }
  cout << ans << endl;
  return 0;
}
