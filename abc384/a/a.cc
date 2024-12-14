#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  char c1, c2;
  cin >> N >> c1 >> c2;
  string S;
  cin >> S;
  string ans;
  for (char c : S) {
    if (c == c1) {
      ans.push_back(c);
    } else {
      ans.push_back(c2);
    }
  }
  cout << ans << endl;
  return 0;
}
