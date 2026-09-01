#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> X(N + 2), S(N + 2);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> S.at(i);
  }
  X.at(N) = -2e9;
  X.at(N + 1) = 2e9;
  S.at(N) = 0;
  S.at(N + 1) = 0;
  set<pair<int, int>> st;
  for (int i = 0; i <= N + 1; i++) {
    st.insert(make_pair(X.at(i), i));
  }
  for (int qi = 0; qi < Q; qi++) {
    int P;
    cin >> P;
    auto right = st.lower_bound(make_pair(P, 0));
    auto left = prev(st.lower_bound(make_pair(P, 0)));
    int ri = right->second;
    int li = left->second;
    // 両端チェック
    if (ri == N + 1) {
      cout << li + 1 << '\n';
      st.erase(left);
      continue;
    }
    if (li == N) {
      cout << ri + 1 << '\n';
      st.erase(right);
      continue;
    }
    // 1
    if (right->first - P < P - left->first) {
      cout << ri + 1 << '\n';
      st.erase(right);
      continue;
    } else if (right->first - P > P - left->first) {
      cout << li + 1 << '\n';
      st.erase(left);
      continue;
    }
    // 2
    int Sr = S.at(ri);
    int Sl = S.at(li);
    if (Sr > Sl) {
      cout << ri + 1 << '\n';
      st.erase(right);
      continue;
    } else if (Sr > Sl) {
      cout << li + 1 << '\n';
      st.erase(left);
      continue;
    }
    // 3
    if (ri < li) {
      cout << ri + 1 << '\n';
      st.erase(right);
    } else {
      cout << li + 1 << '\n';
      st.erase(left);
    }
  }
  return 0;
}
