#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  const long long INF = 4e18;
  vector<pair<long long, long long>> LR(M + 1);
  for (int j = 0; j < M; j++) {
    cin >> LR.at(j).first >> LR.at(j).second;
  }
  LR.at(M) = make_pair(INF, INF + 1);
  sort(LR.begin(), LR.end());
  long long c = 0; // どこまでカバーしたか
  int j = 0;
  while (true) {
    // カバーできる所は全部カバーする
    while (j < M) {
      auto [L, R] = LR.at(j);
      if (L <= c + 1) {
        c = max(c, R);
        j++;
      } else {
        break;
      }
    }
    // まける個数
    long long L = LR.at(j).first;
    long long now = L - c - 1;
    if (now >= N) {
      cout << c + N << endl;
      return 0;
    } else {
      N -= now;
      c = L - 1;
    }
  }
  return 0;
}
