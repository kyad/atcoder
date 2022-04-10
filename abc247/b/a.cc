#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  vector<string> T(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n) >> T.at(n);
  }
  bool ans = true;
  for (int n = 0; n < N; n++) {
    set<string> st;
    for (int i = 0; i < N; i++) {
      if (i == n) {
        continue;
      }
      st.insert(S.at(i));
      st.insert(T.at(i));
    }
    if (st.count(S.at(n)) > 0 && st.count(T.at(n)) > 0) {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
