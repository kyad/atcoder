#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int lower = 0;
  int upper = 0;
  for (char c : S) {
    if (islower(c)) {
      lower++;
    } else {
      upper++;
    }
  }
  string ans;
  for (char c : S) {
    if (lower < upper) {
      ans.push_back(toupper(c));
    } else {
      ans.push_back(tolower(c));
    }
  }
  cout << ans << endl;
  return 0;
}
