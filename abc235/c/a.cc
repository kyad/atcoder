#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  map<int, vector<int> > mp;
  for (int n = 0; n < N; n++) {
    int a;
    cin >> a;
    mp[a].push_back(n + 1);
  }
  for (int q = 0; q < Q; q++) {
    int x, k;
    cin >> x >> k;
    if (mp.count(x) > 0 && k - 1 < (int)mp[x].size()) {
      cout << mp[x][k - 1] << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
