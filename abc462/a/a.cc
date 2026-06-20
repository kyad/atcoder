#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;
  string ans;
  for (char c : S) {
   if ('0' <= c && c <= '9') {
     ans.push_back(c);
   }
  }
   cout << ans << endl;
  return 0;
}
