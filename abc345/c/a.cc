#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long comb2(long long N) { return N * (N - 1) / 2; }

int main() {
  string S;
  cin >> S;
  //int N = S.size();
  vector<long long> n(26, 0);
  for (char c : S) {
    n[c - 'a']++;
  }
  long long ans = 0;
  // S!=操作後の時
  for (int i = 0; i < 26; i++) {
    for (int j = i + 1; j < 26; j++) {
      long long now = n[i] * n[j];
      ans += now;
    }
  }
  // S==操作後の時
  {
    long long now = 0;
    for (int i = 0; i < 26; i++) {
      if (n[i] >= 2) {
        now = 1;
        break;
      }
    }
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
