#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> count(N + 1, 0);
  set<pair<int, int> > st;  // (-票数, 候補者)
  for (int A = 1; A <= N; A++) {
    st.insert(make_pair(-count[A], A));
  }
  for (int m = 0; m < M; m++) {
    // Add
    int A;
    cin >> A;
    assert(st.count(make_pair(-count[A], A)) > 0);
    st.erase(make_pair(-count[A], A));
    count[A]++;
    st.insert(make_pair(-count[A], A));
    // Show
    int ans = st.begin()->second;
    cout << ans << '\n';
  }
  return 0;
}
