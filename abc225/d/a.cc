#include <iostream>
#include <vector>
using namespace std;

// vector
template<class T> ostream& operator<<(ostream& os, const vector<T> &v) {
  size_t N = v.size();
  int MOD = N;
  os << '[';
  for (size_t i = 0; i < N; i++) {
    os << v[i];
    if (i % MOD == (MOD - 1)) {
      os << '\n';
    } else if (i != N - 1) {
      os << ' ';
    }
  }
  os << ']';
  return os;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> id_prev(N + 1, -1);
  vector<int> id_next(N + 1, -1);
  for (int q = 0; q < Q; q++) {
    int no;
    cin >> no;
    if (no == 1) {
      int x, y;
      cin >> x >> y;
      id_next[x] = y;
      id_prev[y] = x;
    } else if (no == 2) {
      int x, y;
      cin >> x >> y;
      id_next[x] = -1;
      id_prev[y] = -1;
    } else {
      int x;
      cin >> x;
      int start = x;
      while (x != -1) {
        start = x;
        x = id_prev[x];
      }
      vector<int> ans;
      int y = start;
      do {
        ans.push_back(y);
        y = id_next[y];
      } while (y != -1);
      cout << ans.size();
      for (size_t i = 0; i < ans.size(); i++) {
        cout << ' ' << ans[i];
      }
      cout << endl;
    }
  }
  return 0;
}
