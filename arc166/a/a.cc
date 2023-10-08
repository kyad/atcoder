#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void testcase() {
  int N;
  string X, Y;
  cin >> N >> X >> Y;
  vector<int> xa, xb, xc;
  vector<int> ya, yb;
  set<int> is;

  auto check = [&](int i) -> bool {

    if (i < N && X[i] != 'C') {
      return false;
    }

    if (xa.size() > ya.size()) {
      return false;
    }

    if (xb.size() > yb.size()) {
      return false;
    }

    int add = (int)yb.size() - (int)xb.size();
    for (int i = 0; i < add; i++) {
      int j = (int)xc.size() - 1 - i;
      assert(0 <= j);
      xb.push_back(xc.at(j));
    }

    sort(xb.begin(), xb.end());
    sort(yb.begin(), yb.end());

    int M = xb.size();
    assert((int)yb.size() == M);
    for (i = 0; i < M; i++) {
      if (xb[i] < yb[i]) {
        return false;
      }
    }
    return true;

  };

  for (int i = 0; i < N; i++) {
    if (Y[i] == 'C') {
      if (!check(i)) {
        cout << "No" << '\n';
        return;
      }
      xa.clear(); xb.clear(); xc.clear();
      ya.clear(); yb.clear();
    } else {
      if (X[i] == 'A') xa.push_back(i);
      else if (X[i] == 'B') xb.push_back(i);
      else xc.push_back(i);
      if (Y[i] == 'A') ya.push_back(i);
      else if (Y[i] == 'B') yb.push_back(i);
      else assert(false);
    }
  }
  if (Y[N - 1] != 'C') {
    if (!check(N)) {
      cout << "No" << '\n';
      return;
    }
  }
  cout << "Yes" << '\n';
}

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    testcase();
  }
  return 0;
}
