#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<string, int> mp;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    int M = S.size();
    for (int j = 0; j < M; j++) {
      if (S.at(j) >= 'a') {
        S.at(j) -= 'a';
        S.at(j) += 'A';
      }
    }
    mp[S]++;
  }
  int ans = 0;
  for (auto [S, num]: mp) {
    ans = max(ans, num);
  }
  cout << ans << '\n';
  return 0;
}
