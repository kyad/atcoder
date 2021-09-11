// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_a

#include <iostream>
#include <stack>
using namespace std;

int main() {
  int n;
  cin >> n;
  stack<pair<int, int> > s;
  for (int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    int add = 1;
    if (i % 2 == 0) {
      if (!s.empty()) {
        if (s.top().first != c) {
          add += s.top().second;
          s.pop();
        }
      }
    }
    if (!s.empty() && s.top().first == c) {
      s.top().second += add;
    } else {
      s.push(make_pair(c, add));
    }
  }
  int ans = 0;
  while (!s.empty()) {
    if (s.top().first == 0) {
      ans += s.top().second;
    }
    s.pop();
  }
  cout << ans << endl;
  return 0;
}
