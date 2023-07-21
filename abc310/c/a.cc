#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<string> st;
  for (int n = 0; n < N; n++) {
    string S;
    cin >> S;
    string T(S);
    reverse(T.begin(), T.end());
    if (S < T) {
      st.insert(S);
    } else {
      st.insert(T);
    }
  }
  cout << st.size() << endl;
  return 0;
}
