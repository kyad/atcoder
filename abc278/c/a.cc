#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  set<pair<int, int> > follow;
  for (int q = 0; q < Q; q++) {
    int T, A, B;
    cin >> T >> A >> B;
    pair<int, int> p = make_pair(A, B);
    if (T == 1) {
      follow.insert(p);
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
