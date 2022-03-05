#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  vector<char> v;
  for (size_t i = 0; i < S.size(); i++) {
    v.push_back(S[i]);
  }
  sort(v.begin(), v.end());
  string ans;
  for (size_t i = 0; i < S.size(); i++) {
    ans += v[i];
  }
  cout << ans << endl;
  return 0;
}
