#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T.at(i);
  }
  const int MX = 1e8+1e6+1;
  vector<int> I(MX + 1, -1);  // >=0の場合、到着する人のidx
  vector<int> J(MX + 1, -1);  // >=0の場合、購入し終わる人のidx
  int cus = -1;  // >=0の場合、今購入している客
  queue<int> q;  // 今購入している人も先頭
  for (int i = 0; i < N; i++) {
    I.at(T.at(i)) = i;
  }
  vector<int> ans(N, -1);
  for (int t = 0; t <= MX; t++) {
    // 購入終了
    if (J.at(t) >= 0) {
      q.pop();
      cus = -1;
      ans.at(J.at(t)) = t;
    }
    // 列に並ぶ
    if (I.at(t) >= 0) {
      q.push(I.at(t));
    }
    // 購入開始
    if (cus < 0 && !q.empty()) {
      cus = q.front();
      J.at(t + A) = cus;
    }
  }
  for (int i = 0; i < N; i++) {
    assert(ans.at(i) >= 0);
    cout << ans.at(i) << '\n';
  }
  return 0;
}
