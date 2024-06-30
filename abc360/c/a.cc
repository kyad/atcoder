#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), W(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    A.at(i)--;
  }
  for (int i = 0; i < N; i++) {
    cin >> W.at(i);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += W.at(i);
  }
  vector<set<int> > st(N);
  for (int i = 0; i < N; i++) {
    st[A.at(i)].insert(W.at(i));
  }
  for (int a = 0; a < N; a++) {
    if (st[a].empty()) {
      continue;
    }
    ans -= *st[a].rbegin();
  }
  cout << ans << endl;
  return 0;
}
