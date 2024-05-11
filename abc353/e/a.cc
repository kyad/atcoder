#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve(int N, const vector<string> &S) {
  // j文字目がcのiの最大値+1を見つける
  auto g = [&](int i0, int i1, int j, char c) {
    int left = i0;  // OK
    int right = i1; // NG
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if ((int)S.at(i0).size() > j && S.at(mid).at(j) == c) {
        // OK
        left = mid;
      } else {
        // NG
        right = mid;
      }
    }
    return right;
  };
  long long ans = 0;
  for (int i = 0; i < N - 1; i++) {
    int M = S.at(i).size();
    int i0 = i;
    int i1 = N;
    for (int j = 0; j < M; j++) {
      char c = S.at(i).at(j);
      int ni1 = g(i0, i1, j, c);
      long long now = ni1 - i - 1;
      ans += now;
      i1 = ni1;
    }
  }
  cout << ans << endl;
}

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  sort(S.begin(), S.end());
  solve(N, S);
  return 0;
}
