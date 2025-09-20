#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<bool> > solve(N, vector<bool>(M, false));
  auto check = [&](int i) {  // 人iが全問正解したか
    bool ans = true;
    for (int j = 0; j < M; j++) {
      if (solve.at(i).at(j) == false) {
        ans = false;
      }
    }
    return ans;
  };
  vector<int> ans;
  for (int k = 0; k < K; k++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    solve.at(A).at(B) = true;
    if (check(A)) {
      ans.push_back(A + 1);
    }
  }
  dump(ans);
  return 0;
}
