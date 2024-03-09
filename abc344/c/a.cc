#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  int M;
  cin >> M;
  vector<int> B(M);
  for (int n = 0; n < M; n++) {
    cin >> B.at(n);
  }
  int L;
  cin >> L;
  vector<int> C(L);
  for (int l = 0; l < L; l++) {
    cin >> C.at(l);
  }
  set<int> st;
  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      for (int l = 0; l < L; l++) {
        int now = A[n] + B[m] + C[l];
        st.insert(now);
      }
    }
  }
  int Q;
  cin >> Q;
  for (int qi = 0; qi < Q; qi++) {
    int X;
    cin >> X;
    bool ans = st.contains(X);
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}
