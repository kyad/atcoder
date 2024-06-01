#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  vector<int> A(T);
  for (int n = 0; n < T; n++) {
    cin >> A.at(n);
  }

  vector<vector<int> > S(N, vector<int>(N));
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      S.at(y).at(x) = N * x + y + 1;
    }
  }
  vector<set<int> > R(N), C(N), D(2);
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      R.at(y).insert(S.at(y).at(x));
    }
  }
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < N; y++) {
      C.at(x).insert(S.at(y).at(x));
    }
  }
  for (int y = 0; y < N; y++) {
    int x = y;
    D.at(0).insert(S.at(y).at(x));
  }
  for (int y = 0; y < N; y++) {
    int x = N - 1 - y;
    D.at(1).insert(S.at(y).at(x));
  }
  auto f = [&](int T) -> bool {
    T--;
    int y = T / N;
    int x = T % N;
    int s = S.at(y).at(x);
    bool ans = false;
    for (int y = 0; y < N; y++) {
      if (R.at(y).contains(s)) {
        R.at(y).erase(s);
        if (R.at(y).empty()) {
          ans = true;
        }
      }
    }
    for (int x = 0; x < N; x++) {
      if (C.at(x).contains(s)) {
        C.at(x).erase(s);
        if (C.at(x).empty()) {
          ans = true;
        }
      }
    }
    for (int i = 0; i < 2; i++) {
      if (D.at(i).contains(s)) {
        D.at(i).erase(s);
        if (D.at(i).empty()) {
          ans = true;
        }
      }
    }
    return ans;
  };

  int ans = -1;
  for (int t = 0; t < T; t++) {
    bool now = f(A.at(t));
    if (now) {
      ans = t + 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
