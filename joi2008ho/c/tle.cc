// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c
// TLE

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  set<int> st;
  st.insert(0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      st.insert(P[i] + P[j]);
    }
    st.insert(P[i]);
  }
  // 合計x点以上にできるか？
  int left = 0;  // できる
  int right = M + 1; // できない
  while (right - left > 1) {
    int mid = (left + right) / 2;
    int ok = false;
    for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
      int a = *it;
      set<int>::iterator j = st.lower_bound(mid - a);
      if (j != st.end() && a + *j <= M) {
        ok = true;
      }
    }
    if (ok) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << left << endl;
  return 0;
}
