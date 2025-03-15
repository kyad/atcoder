#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  string T;
  int ans = 0;
  for (char c : S) {
    if (T.size() % 2 == 0) {  // 偶数の時、次は奇数なのでi
      if (c == 'o') {
        T.push_back('i');
        ans++;
      }
    } else {  // 偶数の時、次は奇数なのでo
      if (c == 'i') {
        T.push_back('o');
        ans++;
      }
    }
    T.push_back(c);
  }
  if (T.size() % 2 == 1) {  // 'i'で終わる時
    T.push_back('o');
    ans++;
  }
  cout << ans << endl;
  return 0;
}
