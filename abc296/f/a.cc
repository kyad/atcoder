#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#include <atcoder/scc>
using namespace atcoder;

bool check_perm(const vector<int>& A) {
  set<int> st;
  for (int a : A) {
    st.insert(a);
  }
  return A.size() == st.size();
}

// 0->A[0], 1->A[1], ...が偶置換か奇置換かを返す
// A and A's values are 0-indexed
// true: 奇置換、false: 偶置換
bool sgn(const vector<int>& A) {
  int N = A.size();
  scc_graph graph(N);
  for (int n = 0; n < N; n++) {
    graph.add_edge(n, A[n]);
  }
  vector<vector<int> > scc = graph.scc();
  return ((int)scc.size() % 2) == (N % 2);
}

bool solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(N);
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }
  // Check whether A and B are same set
  {
    vector<int> aa(A), bb(B);
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    if (aa != bb) {
      return false;
    }
  }
  // Check if permutation
  if (!check_perm(A)) {
    return true;
  }
  // A is permutation
  // A, Bの値を0-indexedにする
  for (int n = 0; n < N; n++) {
    A[n]--; B[n]--;
  }
  return sgn(A) == sgn(B);
}

int main() {
  bool ans = solve();
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
