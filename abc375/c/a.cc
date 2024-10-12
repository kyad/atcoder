#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  vector<string> B(A);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      B.at(i).at(j) = '-';
    }
  }
  const int dy[4] = {0, 1, 0, -1};
  const int dx[4] = {1, 0, -1, 0};
  for (int i = 0; i < N / 2; i++) {
    int count = i + 1;  // 右回転する回数
    // A
    int ay = i;
    int ax = i;
    int ak = 0;  // 方向
    // B
    int by, bx;
    if (count % 4 == 0) {
      by = i;
      bx = i;
    } else if (count % 4 == 1) {
      by = i;
      bx = N - 1 - i;
    } else if (count % 4 == 2) {
      by = N - 1 - i;
      bx = N - 1 - i;
    } else {
      by = N - 1 - i;
      bx = i;
    }
    int bk = count % 4;  // 方向
    while (true) {
      B.at(by).at(bx) = A.at(ay).at(ax);
      // Aを1進める処理
      int nay = ay + dy[ak];
      int nax = ax + dx[ak];
      if (nay == i && nax == i) {  // 初期位置に戻った
        break;
      }
      if (nay < i || nay > N - 1 - i || nax < i || nax > N - 1 - i) {  // 枠外
        ak = (ak + 1) % 4;
        nay = ay + dy[ak];
        nax = ax + dx[ak];
        assert(nay >= i && nay <= N - 1 - i && nax >= i && nax <= N - 1 - i);  // 枠内にいることの確認
        if (nay == i && nax == i) {  // 初期位置に戻った
          break;
        }
        bk = (bk + 1) % 4;
      }
      ay = nay;
      ax = nax;
      // Bを1進める処理
      by = by + dy[bk];
      bx = bx + dx[bk];
    }
  }
  for (int i = 0; i < N; i++) {
    cout << B.at(i) << '\n';
  }
  return 0;
}
