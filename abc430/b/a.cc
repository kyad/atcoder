#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int y = 0; y < N; y++) {
    cin >> S.at(y);
  }
  set<vector<string> > st;
  auto f = [&](int y0, int x0) {
    vector<string> ans;
    for (int y = y0; y < y0 + M; y++) {
      string line;
      for (int x = x0; x < x0 + M; x++) {
        line.push_back(S.at(y).at(x));
      }
      ans.push_back(line);
    }
    return ans;
  };
  for (int y = 0; y < N; y++) {
    if (y + M > N) {
      continue;
    }
    for (int x = 0; x < N; x++) {
      if (x + M > N) {
        continue;
      }
      vector<string> now = f(y, x);
      st.insert(now);
    }
  }
  int ans = st.size();
  cout << ans << endl;
  return 0;
}
