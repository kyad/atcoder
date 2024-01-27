#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<int> cnt(26, 0);
  for (char c : S) {
    cnt.at(c - 'a')++;
  }
  int mx = -1;
  int ans = -1;
  for (int i = 0; i < 26; i++) {
    if (cnt[i] > mx) {
      ans = i;
      mx = cnt[i];
    }
  }
  assert(ans >= 0);
  char a = 'a' + ans;
  cout << a << endl;
  return 0;
}
