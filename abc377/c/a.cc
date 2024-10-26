#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  const int dy[8] = {-1, -2,  -2, -1,   1,  2,  2,  1};
  const int dx[8] = { 2,  1,  -1, -2,  -2, -1,  1,  2};
  set<pair<int, int> > st;
  for (int j = 0; j < M; j++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    st.insert(make_pair(a, b));
    // knightのチェック
    for (int k = 0; k < 8; k++) {
      int y = a + dy[k];
      int x = b + dx[k];
      if (y < 0 || y >= N || x < 0 || x >= N) {
        continue;
      }
      st.insert(make_pair(y, x));
    }
  }
  long long ans = (long long)N * N;
  ans -= (long long)st.size();
  cout << ans << endl;
  return 0;
}
