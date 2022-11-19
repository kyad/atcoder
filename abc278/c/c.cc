// https://atcoder.jp/contests/abc278/tasks/abc278_c

#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  map<pair<int, int>, int> follow;
  for (int q = 0; q < Q; q++) {
    int T, A, B;
    cin >> T >> A >> B;
    pair<int, int> p = make_pair(A, B);
    if (T == 1) {
      follow[p] = 1;
    } else if (T == 2) {
      if (follow.count(p) > 0) {
        follow.erase(p);
      }
    } else {
      pair<int, int> q = make_pair(B, A);
      if (follow.count(p) > 0 && follow.count(q) > 0) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
