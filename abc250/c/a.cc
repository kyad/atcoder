#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> v(N + 1, 0);
  map<int, int> mp;
  for (int n = 1; n <= N; n++) {
    v[n] = n;
    mp[n] = n;
  }
  for (int q = 0; q < Q; q++) {
    int x;
    cin >> x;
    int pos = mp[x];
    int r;
    if (pos == N) {
      r = pos - 1;
    } else {
      r = pos + 1;
    }
    int y = v[r];
    v[pos] = y;
    v[r] = x;
    mp[x] = r;
    mp[y] = pos;
  }
  for (int n = 1; n <= N; n++) {
    cout << v[n] << (n == N ? '\n' : ' ');
  }
  return 0;
}
