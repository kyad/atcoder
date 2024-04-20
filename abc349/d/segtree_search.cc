// https://www.youtube.com/watch?v=4H4IL1_M7ao&t=2323s

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Search for [L, R)
vector<pair<long long, long long> > segtree_search(long long L, long long R) {
  assert(L >= 0);
  assert(L <= R);
  vector<pair<long long, long long> > ans;
  long long width = 1;
  long long shift = 0;
  while (L < R) {
    if (L & 1LL) {
      ans.emplace_back((L << shift), (L << shift) + width);
      L++;
    }
    if (R & 1LL) {
      ans.emplace_back((R << shift) - width, (R << shift));
      R--;
    }
    L >>= 1LL;
    R >>= 1LL;
    width <<= 1LL;
    shift++;
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  long long L, R;
  cin >> L >> R;
  vector<pair<long long, long long> > ans = segtree_search(L, R);
  int M = ans.size();
  cout << M << endl;
  for (auto [l, r]: ans) {
    cout << l << ' ' << r << '\n';
  }
  return 0;
}
