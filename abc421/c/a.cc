#include <algorithm>
#include <cassert>
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  deque<int> As;
  deque<int> Bs;
  for (int i = 0; i < N * 2; i++) {
    if (S.at(i) == 'A') {
      As.push_back(i);
    } else {
      Bs.push_back(i);
    }
  }
  auto solve = [&](deque<int> As, deque<int> Bs) {
    long long ans =0;
    for (int i = 0; i < N * 2; i++) {
      long long now;
      if (i % 2 == 0) {  // 'A'を期待
        int x = *As.begin();
        now = distance(Bs.begin(), lower_bound(Bs.begin(), Bs.end(), x));
        As.pop_front();
      } else {  // 'B'を期待
        int x = *Bs.begin();
        now = distance(As.begin(), lower_bound(As.begin(), As.end(), x));
        Bs.pop_front();
      }
      ans += now;
    }
    return ans;
  };
  long long ans1 = solve(As, Bs);
  long long ans2 = solve(Bs, As);
  long long ans = min(ans1, ans2);
  cout << ans << endl;
  return 0;
}
