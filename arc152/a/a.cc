#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  vector<int> A(N, 0);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  bool ans = true;
  int l = -1;  // 1個とばしで置く時、前回置いた座標
  vector<int> P;
  size_t pi = 0;
  auto add = [&](int a) {
    if (l + a == L - 1) {  // つめる
      l += a;
    } else {  // 1個あける
      P.push_back(l + 1);
      l += (a + 1);
    }
    if (l > L - 1) {
      return false;
    } else {
      return true;
    }
  };
  for (int n = 0; n < N; n++) {
    bool now = add(A[n]);

    if (!now && A[n] == 1) {
      if (pi >= P.size()) {  // Pを使わない
      } else {  // Pを使う
        pi++;
        now = true;
      }
    }

    if (!now) {
      ans = false;
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
