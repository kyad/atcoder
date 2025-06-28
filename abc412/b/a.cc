#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  set<char> st;
  for (char t : T) {
    st.insert(t);
  }
  int N = S.size();
  bool ans = true;
  for (int i = 1; i < N; i++) {
    char s = S.at(i);
    if ('A' <= s && s <= 'Z') {
      char c = S.at(i - 1);
      if (!st.contains(c)) {
        ans = false;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
