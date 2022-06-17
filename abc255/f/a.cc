// https://atcoder.jp/contests/abc255/tasks/abc255_f

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
    P.at(n)--;
  }
  vector<int> I(N);
  map<int, int> mp;
  for (int n = 0; n < N; n++) {
    cin >> I.at(n);
    I.at(n)--;
    mp[I.at(n)] = n;
  }
  vector<int> L(N, -1);
  vector<int> R(N, -1);
  // 行きがけ順がPの[p, p+n), 帰りがけ順がIの[i, i+n)である木が存在するか
  // 存在する: rootの番号、存在しない: -1
  auto f = [&](auto f, int p, int i, int n) -> int {
    const int root = P[p];  // 頂点の数字(0-indexed)
    if (n == 1) {
      return P[p] == I[i] ? root : -1;
    }
    const int left_len = mp[root] - i;
    if (left_len > 0) {
      L[root] = f(f, p + 1, i, left_len);
      if (L[root] < 0) {
        return -1;
      }
    } else if (left_len < 0) {
      return -1;
    }
    const int right_len = n - 1 - left_len;
    if (right_len > 0) {
      R[root] = f(f, p + left_len + 1, mp[root] + 1, right_len);
      if (R[root] < 0) {
        return -1;
      }
    } else if (right_len < 0) {
      return -1;
    }
    return root;
  };
  int root = f(f, 0, 0, N);
  if (root == 0) {
    for (int n = 0; n < N; n++) {
      cout << (L.at(n) + 1) << ' ' << (R.at(n) + 1) << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
