#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, L, R;
  cin >> N >> L >> R;
  string S;
  cin >> S;
  S.insert(S.begin(), '_');
  vector<vector<int> > C(2 * N + 1, vector<int>(26, 0));
  for (int i = 1; i <= N; i++) {
    int c = S.at(i) - 'a';
    C.at(i).at(c)++;
  }
  vector<vector<int> > T(C);
  for (int i = 1; i <= 2 * N; i++) {
    for (int c = 0; c < 26; c++) {
      T.at(i).at(c) += T.at(i - 1).at(c);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    int c = S.at(i) - 'a';
    long long now = T.at(i + R).at(c) - T.at(i + L - 1).at(c);
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
