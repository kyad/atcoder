#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N;
  N = S.size();
  vector<bool> used(26, false);
  stack<vector<int> > st;
  vector<int> now;
  st.push(now);
  for (int n = 0; n < N; n++) {
    if (S[n] == '(') {
      vector<int> now;
      st.push(now);
    } else if (S[n] == ')') {
      assert(!st.empty());
      for (int value : st.top()) {
        assert(used[value]);
        used[value] = false;
      }
      st.pop();
    } else {
      int value = S[n] - 'a';
      if (used[value]) {
        cout << "No" << endl;
        return 0;
      }
      used[value] = true;
      st.top().push_back(value);
    }
  }
  cout << "Yes" << endl;
  return 0;
}
