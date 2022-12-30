// https://atcoder.jp/contests/abc281/tasks/abc281_f

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int dfs(const vector<int>& A, int l, int r) {
  if (l == r) {
    return 0;
  }
  int x = 0, y = 0;
  for (int i = 29; i >= 0; i--) {
    int lsb_l = (A[l]>>i)&1;
    int lsb_r = (A[r]>>i)&1;
    if (lsb_l == lsb_r) {
      x |= (lsb_l<<i);
      continue;
    }
    x |= (1<<i);
    y = (1<<i);
    break;
  }
  int n = lower_bound(A.begin() + l, A.begin() + r + 1, x) - (A.begin() + l);
  int la = l;
  int ra = l + n - 1;
  int lb = l + n;
  int rb = r;
  assert(la <= ra);
  assert(lb <= rb);
  int ans = min(dfs(A, la, ra), dfs(A, lb, rb)) + y;
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  cout << dfs(A, 0, A.size() - 1) << endl;
  return 0;
}
