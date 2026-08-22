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
    if (c != 'A') {
      ans.push_back('.');
    } else {
      ans.push_back('A');
    }
  }
  cout << ans << '\n';
  return 0;
}
