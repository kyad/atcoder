#include <algorithm>
#include <iostream>
#include <cassert>
#include <set>
#include <vector>

using namespace std;

long long comb2(long long n) {
  long long ans  = n *  (n - 1) / 2;
  return ans;
 }

int main() {
  int N, D;
  cin >> N >> D;
  vector<int> S(N), T(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i) >> T.at(i);
  }
  int M = 1000000;
  vector<vector<int> > in(M + 1), out(M + 1);
  for (int i = 0; i < N; i++) {
    if (T.at(i) - S.at(i) < D) {
      continue;
    }
    in.at(S.at(i)).push_back(i);
    out.at(T.at(i)).push_back(i);
  }
  set<int> st;
  long long ans = 0;
  for (int t = 1; t + D <= M; t++) {
    for (int i : in.at(t)) {
      st.insert(i);
    }
    long long now = comb2(st.size());
    ans += now; 
    for (int i : out.at(t + D)) {
      if (!st.contains(i)) {
        assert(false);
      }
      st.erase(i);
    }
  }
  cout << ans << endl;
  return 0;
}
