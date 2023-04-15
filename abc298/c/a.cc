#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<multiset<int> > S(200001);
  vector<set<int> > T(200001);
  int Q;
  cin >> Q;
  for (int q = 0; q < Q; q++) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, j;
      cin >> i >> j;
      S[j].insert(i);
      T[i].insert(j);
    } else if (type == 2) {
      int j;
      cin >> j;
      vector<int> now;
      for (int i : S[j]) {
        now.push_back(i);
      }
      for (size_t k = 0; k < now.size(); k++) {
        cout << now[k] << " \n"[k + 1 == now.size()];
      }
    } else {
      int i;
      cin >> i;
      vector<int> now;
      for (int j : T[i]) {
        now.push_back(j);
      }
      for (size_t k = 0; k < now.size(); k++) {
        cout << now[k] << " \n"[k + 1 == now.size()];
      }
    }
  }
  return 0;
}
