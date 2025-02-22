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
    if (c == '2') {
      ans.push_back(c);
    }
  }
  cout << ans << endl;
  return 0;
}
