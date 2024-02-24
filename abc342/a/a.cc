#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  map<char, int> mp;
  for (char c : S) {
    mp[c]++;
  }
  int N = S.size();
  char a = '.';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second == 1) {
      a = it->first;
    }
  }
  int ans = -1;
  for (int i = 0; i < N; i++) {
    if (S[i] == a) {
      ans = i + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
