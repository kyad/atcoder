// https://www.youtube.com/watch?v=pnL194JdbKM&t=5873s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<vector<int> > is(3);
  for (int i = 0; i < N; i++) {
    int c;
    if (S.at(i) == '/') {
      c = 0;
    } else {
      c = S.at(i) - '1' + 1;
    }
    is.at(c).push_back(i);
  }

  const int INF = 1e9;

  // iから見て文字cがx個出たとして、その次のidxを返す
  auto get_next = [&](int c, int i, int x) -> int {
    if (x == 0) {
      return i;
    }
    const vector<int> &nis = is.at(c);
    int j = lower_bound(nis.begin(), nis.end(), i) - nis.begin() + (x - 1);
    if (j < (int)nis.size()) {
      return nis.at(j) + 1;
    } else {
      return INF;
    }
  };

  for (int qi = 0; qi < Q; qi++) {
    int L, R;
    cin >> L >> R;
    L--;

    // 1の個数がkの11/22文字列を作れるか？
    auto judge = [&](int k) -> bool {
      int i = L;
      i = get_next(1, i, k);
      i = get_next(0, i, 1);
      i = get_next(2, i, k);
      if (i <= R) {
        return true;
      } else {
        return false;
      }
    };

    int left = -1;  // OK
    int right = N;  // NG
    while (right - left > 1) {
      int mid = (left + right) / 2;
      if (judge(mid)) {
        left = mid;
      } else {
        right = mid;
      }
    }
    int ans;
    if (left == -1) {
      ans = 0;
    } else {
      ans = 2 * left + 1;
    }
    cout << ans << '\n';
  }

  return 0;
}
