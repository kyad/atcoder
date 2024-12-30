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
  // 最初
  int ans = 0;
  for (int i = 0; i + 2 <= N - 1; i++) {
    string T = S.substr(i, 3);
    if (T == "ABC") ans++;
  }
  // Sのlから3文字のうちiがcに変わった時の答えへの寄与
  auto f = [&](int l, int i, char c) {
    int ans = 0;
    string P = S.substr(l, 3);
    string Q(P);
    Q.at(i) = c;
    if (P == "ABC") ans--;
    if (Q == "ABC") ans++;
    return ans;
  };
  for (int qi = 0; qi < Q; qi++) {
    int i;
    char C;
    cin >> i >> C;
    i--;
    int now = 0;
    if (i - 2 >= 0)                   now += f(i - 2, 2, C);
    if (i - 1 >= 0 && i + 1 <= N - 1) now += f(i - 1, 1, C);
    if (i + 2 <= N - 1)               now += f(i, 0, C);
    ans += now;
    cout << ans << '\n';
    S.at(i) = C;
  }
  return 0;
}
