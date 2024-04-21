// https://atcoder.jp/contests/arc176/editorial/9815

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<bool> S(N, false);
  int nS = 0;
  for (int m = 0; m < M; m++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    int k = (A + B) % N;
    if (S[k] == false) {
      S[k] = true;
      nS++;
    }
  }
  for (int k = 0; k < N; k++) {
    if (nS >= M) {
      break;
    }
    if (S[k] == true) {
      continue;
    }
    S[k] = true;
    nS++;
  }
  vector<pair<int, int> > ans;
  for (int k = 0; k < N; k++) {
    if (S[k] == false) {
      continue;
    }
    for (int y = 0; y < N; y++) {
      int x = (k - y + N) % N;
      ans.emplace_back(x + 1, y + 1);
    }
  }
  int k = ans.size();
  cout << k << '\n';
  for (auto [x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
  return 0;
}
