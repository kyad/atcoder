// https://atcoder.jp/contests/abc247/tasks/abc247_e

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  // [l, r] の区間内が全てY以上X以下であるようにする
  int l = 0;
  int r = 0;
  long long ans = 0;
  while (true) {
    // lを探す
    for (; l < N; l++) {
      if (A.at(l) >= Y && A.at(l) <= X) {
        break;
      }
    }
    if (l >= N) {
      break;
    }
    // rを探す
    r = l;
    while (r + 1 < N && A.at(r + 1) >= Y && A.at(r + 1) <= X) {
      r++;
    }
    // 対象の数を数える
    vector<int> ix, iy;
    for (int i = l; i <= r; i++) {
      if (A.at(i) == X) {
        ix.push_back(i);
      }
      if (A.at(i) == Y) {
        iy.push_back(i);
      }
    }
    for (int i = l; i <= r; i++) {
      vector<int>::iterator nearX = lower_bound(ix.begin(), ix.end(), i);
      vector<int>::iterator nearY = lower_bound(iy.begin(), iy.end(), i);
      if (nearX == ix.end() || nearY == iy.end()) {
        continue;
      }
      int now = r - max(*nearX, *nearY) + 1;
      ans += (long long)now;
    }
    // Next
    l = r + 1;
  }
  cout << ans << endl;
  return 0;
}
