#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

using lll = __int128;

bool pararel(lll ax, lll ay, lll bx, lll by) {
  if (ax * by == ay * bx) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    long long _PX, _PY, _QX, _QY, _RX, _RY, _SX, _SY;
    cin >> _PX >> _PY >> _QX >> _QY >> _RX >> _RY >> _SX >> _SY;
    lll PX = _PX * 2, PY = _PY * 2, QX = _QX * 2, QY = _QY * 2,
        RX = _RX * 2, RY = _RY * 2, SX = _SX * 2, SY = _SY * 2;
    // PQ//SRか
    lll AX = QX - PX;
    lll AY = QY - PY;
    lll BX = SX - RX;
    lll BY = SY - RY;
    lll UX = -AY, UY = AX;
    lll VX = -BY, VY = BX;
    if (!pararel(UX, UY, VX, VY)) {
      cout << "Yes" << '\n';
      continue;
    }
    // 以下、U//Vの場合
    // 中点が一致するか
    lll NX = (PX + QX) / 2, NY = (PY + QY) / 2;
    lll MX = (RX + SX) / 2, MY = (RY + SY) / 2;
    if (NX == MX && NY == MY) {
      cout << "Yes" << '\n';
      continue;
    }
    // U//Wか
    lll WX = NX - MX, WY = NY - MY;
    if (pararel(UX, UY, WX, WY)) {
      cout << "Yes" << '\n';
      continue;
    }
    cout << "No" << '\n';
  }
  return 0;
}
