#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
      cin >> S.at(i);
    }
    multiset<int> st;
    for (int i = 1; i < N - 1; i++) {
      st.insert(-S.at(i));
    }
    int prev = S.at(0);
    int ans = 1;  // 最初のドミノ
    while (true) {
      if (prev * 2 >= S.at(N - 1)) {  // 最後のドミノを倒して終了
        ans++;  // 最後のドミノ
        break;
      }
      auto it = st.lower_bound(-prev * 2);
      if (it == st.end()) {  // 見つからなかった場合は終了
        ans = -1;
        break;
      }
      st.erase(it);
      prev = -(*it);
      ans++;
    }
    cout << ans << '\n';
  }
  return 0;
}
