#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long comb2(long long N) { return N * (N - 1) / 2; }

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  S.insert(S.begin(), '_');
  vector<int> V(N + 1, 0), F(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    if (S.at(i) == 'V') {
      V.at(i)++;
    } else if (S.at(i) == 'F') {
      F.at(i)++;
    } else if (S.at(i) == 'B') {
      V.at(i)++;
      F.at(i)++;
    }
  }
  for (int i = 1; i <= N; i++) {
    V.at(i) += V.at(i - 1);
    F.at(i) += F.at(i - 1);
  }
  map<int, int> mp;
  for (int i = 0; i <= N; i++) {
    int diff = V.at(i) - F.at(i);
    mp[diff]++;
  }
  long long ans = 0;
  for (auto [diff, count] : mp) {
    long long now = comb2(count);
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
