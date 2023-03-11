#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int> > A(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }
  vector<int> B;
  for (int i = 0; i < H - 1; i++) {
    B.push_back(0);
  }
  for (int j = 0; j < W - 1; j++) {
    B.push_back(1);
  }
  int ans = 0;
  int N = B.size();
  do {
    int ok = true;
    set<int> st;
    int y = 0;
    int x = 0;
    st.insert(A[y][x]);
    for (int n = 0; n < N; n++) {
      if (B.at(n) == 0) {
        y++;
      } else {
        x++;
      }
      assert(y < H);
      assert(x < W);
      if (st.count(A[y][x]) > 0) {
        ok = false;
        break;
      }
      st.insert(A[y][x]);
    }
    if (ok) {
      assert(y == H - 1);
      assert(x == W - 1);
      ans++;
    }
  } while (next_permutation(B.begin(), B.end()));
  cout << ans << endl;
  return 0;
}
