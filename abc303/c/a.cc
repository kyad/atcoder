#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M, H, K;
  cin >> N >> M >> H >> K;
  string S;
  cin >> S;
  set<pair<int, int> > st;
  for (int m = 0; m < M; m++) {
    int x, y;
    cin >> x >> y;
    st.insert(make_pair(x, y));
  }
  int x = 0;
  int y = 0;
  for (int n = 0; n < N; n++) {
    if (S[n] == 'R') {
      x++;
    } else if(S[n] == 'L') {
      x--;
    } else if(S[n] == 'U') {
      y++;
    } else if(S[n] == 'D') {
      y--;
    }
    H--;
    if (H < 0) {
      cout << "No" << endl;
      return 0;
    }
    if (st.count(make_pair(x, y)) > 0 && H < K) {
      H = K;
      st.erase(make_pair(x, y));
    }
  }
  cout << "Yes" << endl;
  return 0;
}
