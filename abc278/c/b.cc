// https://atcoder.jp/contests/abc278/tasks/abc278_c

#include <cassert>
#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  map<int, set<int> > follow;
  for (int q = 0; q < Q; q++) {
    int T, A, B;
    cin >> T >> A >> B;
    if (T == 1) {
      follow[A].insert(B);
    } else if (T == 2) {
      if (follow[A].count(B) > 0) {
        follow[A].erase(B);
      }
    } else {
      if (follow[A].count(B) > 0 && follow[B].count(A) > 0) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
