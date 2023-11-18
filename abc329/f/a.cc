#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> C(N);
  for (int n = 0; n < N; n++) {
    cin >> C.at(n);
  }
  vector<set<int> > st(N);
  for (int n = 0; n < N; n++) {
    st[n].insert(C[n]);
  }
  for (int q = 0; q < Q; q++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    int sa = st[A].size();
    int sb = st[B].size();
    if (sa <= sb) {
      // st[A] -> st[B]
      for (int c : st[A]) {
        st[B].insert(c);
      }
      st[A].clear();
    } else {  // sa > sb
      // st[A] <- st[B]
      for (int c : st[B]) {
        st[A].insert(c);
      }
      st[B].clear();
      swap(st[A], st[B]);
    }
    int ans = st[B].size();
    cout << ans << '\n';
  }
  return 0;
}
