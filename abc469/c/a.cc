#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> ans(N, 0);
  int to = 0;  // 次食べる場所
  for (int i = 0; i < N; i++) {
    while (true) {
      if (to == N) {
        break;
      }
      if (S.at(to) == 'o') {
        to++;
        continue;
      } else {
        to++;
        break;
      }
    }
    ans.at(i) = to;
  }
  for (int i = 0; i < N; i++) {
    cout << ans.at(i) << '\n';
  }
  return 0;
}
