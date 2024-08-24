#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long T = 0;
  for (int i = 0; i < N; i++) {
    long long H;
    cin >> H;
    // Hを正規化
    long long add = T % 3;
    H += add;
    // 1, 1, 3と攻撃する
    long long q = H / 5;
    long long now = q * 3;
    long long r = H % 5;
    if (r <= 2) {
      now += r;
    } else if (r >= 3) {
      now += 3;
    }
    now -= add;  // 正規化で足した分を引く
    T += now;
  }
  cout << T << endl;
  return 0;
}
