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
  vector<bool> A(N - 2, false);  // A[i]: iから始まる3文字がABCかどうか
  auto check = [&](int i) {
    assert(0 <= i);
    assert(i + 2 < N);
    if (S.at(i) == 'A' && S.at(i + 1) == 'B' && S.at(i + 2) == 'C') {
      return true;
    } else {
      return false;
    }
  };
  // SのABCの個数を数える
  int count = 0;
  for (int i = 0; i < N - 2; i++) {
    A.at(i) = check(i);
    if (A.at(i)) {
      count++;
    }
  }
  for (int q = 0; q < Q; q++) {
    int X;
    char C;
    cin >> X >> C;
    X--;
    S.at(X) = C;   //SのX文字目をCにおきかえる
    // 前からの差分を計算する
    for (int i = X - 2; i <= X; i++) {  // 3パターン見る
      if (i < 0 || i >= N - 2) {
        continue;
      }
      bool prev = A.at(i);  // 前の状態でiから始まる3文字がABCだったかどうか
      bool next = check(i); // 次の状態でiから始まる3文字がABCかどうか
      A.at(i) = next;
      if (prev == false && next == true) {  // ABCじゃない→ABC
        count++;
      } else if (prev == true && next == false) {  // ABC→ABCじゃない
        count--;
      }
    }
    cout << count << '\n';
  }
  return 0;
}
