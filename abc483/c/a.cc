#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> C(N);
  set<pair<int, int>> st;
  for (int i = 0; i < N; i++) {
    st.insert(make_pair(0, i));
  }
  vector<int> count(N, 0);
  // xをdeltaだけ増やす
  auto add = [&](int x, int delta) {
    st.erase(st.find(make_pair(-count.at(x), x)));
    count.at(x) += delta;
    st.insert(make_pair(-count.at(x), x));
  };
  
  for (int j = 0; j < M; j++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    C.at(A).push_back(B);
    add(A, 1);
  }
  for (int k = 0; k < N; k++) {
    int first = count.at(k);
    add(k, -first);
    for (int second : C.at(k)) {
      add(second, +1);
    }
    int ans = st.begin()->second + 1;
    cout << ans << '\n';
    for (int second : C.at(k)) {
      add(second, -1);
    }
    add(k, +first);
  }
  return 0;
}
