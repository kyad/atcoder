#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int Q;
  cin >> Q;
  int mode = 0;  // 1: lower, 2: upper
  set<int> st;
  for (int qi = 0; qi < Q; qi++) {
    int T, X;
    char C;
    cin >> T >> X >> C;
    X--;
    if (T == 1) {
      S.at(X) = C;
      st.insert(X);
    } else if (T == 2) {
      mode = 1;
      st.clear();
    } else {
      assert(T == 3);
      mode = 2;
      st.clear();
    }
  }
  string ans;
  for (int n = 0; n < N; n++) {
    char now;
    char c = S.at(n);
    if (st.count(n) > 0) {
      now = c;
    } else {
      if (mode == 0) {
        now = c;
      } else if (mode == 1){
        now = tolower(c);
      } else {
        assert(mode == 2);
        now = toupper(c);
      }
    }
    ans.push_back(now);
  }
  assert(ans.size() == S.size());
  cout << ans << endl;
  return 0;
}
