#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int H, W, N, h, w;
  cin >> H >> W >> N >> h >> w;
  int L = W - w + 1;
  vector<vector<int> > A(H, vector<int>(W, 0));
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> A[y][x];
    }
  }
  map<int, int> all;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      all[A[y][x]]++;
    }
  }
  // First row (k=0)
  vector<map<int, int> > mp(L, all);
  auto remove = [&](int l, int a) {
    assert(mp[l].count(a) > 0);
    if (mp[l][a] == 1) {
      mp[l].erase(a);
    } else {
      mp[l][a]--;
    }
  };
  auto add = [&](int l, int a) {
    mp[l][a]++;
  };
  auto count = [&](int l) -> int {
    return mp[l].size();
  };
  for (int l = 0; l < L; l++) {
    for (int y = 0; y < h; y++) {
      for (int x = l; x < l + w; x++) {
        remove(l, A[y][x]);
      }
    }
    cout << count(l) << (l == L - 1 ? '\n' : ' ');
  }
  // solve
  int K = H - h + 1;
  for (int k = 1; k < K; k++) {
    for (int l = 0; l < L; l++) {
      for (int x = l; x < l + w; x++) {
        add(l, A[k - 1][x]);
        remove(l, A[k + h - 1][x]);
      }
      cout << count(l) << (l == L - 1 ? '\n' : ' ');
    }
  }
  return 0;
}
