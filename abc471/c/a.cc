#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  multiset<long long> ms;
  for (int i = 0; i < N; i++) {
    ms.insert(A.at(i));
  }
  const int INF = 2e9;
  ms.insert(INF);
  ms.insert(-INF);
  long long ans = 0;
  long long x = 0;
  while (ms.size() >= 3) {
    long long right = *ms.lower_bound(x);
    long long left = *prev(ms.lower_bound(x));
    long long nx;
    if (right == INF) {
      assert(left != INF);
      nx = left;
    } else if (left == -INF) {
      assert(right != INF);
      nx = right;
    } else {
      long long diff_r = right - x;
      long long diff_l = x - left;
      if (diff_r >= diff_l) {
        nx = left;
      } else {
        nx = right;
      }
    }
    long long now = abs(x - nx);
    ans += now;
    ms.erase(ms.find(nx));
    x = nx;
  }
  cout << ans << '\n';
  return 0;
}
