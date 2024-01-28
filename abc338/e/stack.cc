// https://atcoder.jp/contests/abc338/editorial/9172

#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> ls, rs;
  vector<int> g(N * 2, -1);
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    int l = min(A, B);
    int r = max(A, B);
    ls.insert(l);
    rs.insert(r);
    g[l] = r;
    g[r] = l;
  }
  stack<int> st;
  for (int u = 0; u < N * 2; u++) {
    if (ls.contains(u)) {
      st.push(u);
    } else {
      int l = g[u];
      if (st.top() != l) {
        cout << "Yes" << endl;
        return 0;
      }
      st.pop();
    }
  }
  cout << "No" << endl;
  return 0;
}
