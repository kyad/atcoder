#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (int y = 0; y < H; y++) {
    cin >> S.at(y);
  }

  // true: 消せた
  // false: 消せない
  auto f = [&](vector<string> &S, vector<int> &removes) -> bool {
    int h = S.size();
    assert(h > 0);
    int w = S[0].size();
    assert(w > 0);
    bool ans = false;
    for (int y = 0; y < h; y++) {
      bool ok = true;
      for (int x = 1; x < w; x++) {
        if (S[y][0] != S[y][x]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans = true;
        removes.push_back(y);
      }
    }
    return ans;
  };
  auto transpose = [&](vector<string>& S) {
    int h = S.size();
    if (h == 0) {
      return;
    }
    int w = S[0].size();
    if (w == 0) {
      return;
    }
    vector<string> T(w);
    for (int x = 0; x < w; x++) {
      string now;
      for (int y = 0; y < h; y++) {
        T[x].push_back(S[y][x]);
      }
    }
    swap(S, T);
  };
  auto shrink = [&](vector<string> &S, vector<int> &removes) {
    vector<string> T;
    int h = S.size();
    int N = removes.size();
    int i = 0;
    for (int y = 0; y < h; y++) {
      if (i < N && removes[i] == y) {
        i++;
        continue;
      }
      T.push_back(S[y]);
    }
    swap(S, T);
  };
  while (true) {
    bool ret1, ret2;
    int h = S.size();
    if (h == 0) {
      break;
    }
    int w = S[0].size();
    if (w == 0) {
      break;
    }
    if (h <= 1 || w <= 1) {
      break;
    }
    // Step 1
    vector<int> remove_ys;
    ret1 = f(S, remove_ys);
    // Step 2
    vector<int> remove_xs;
    transpose(S);
    ret2 = f(S, remove_xs);
    if (!ret1 && !ret2) {
      break;
    }
    // shrink
    shrink(S, remove_xs);
    transpose(S);
    shrink(S, remove_ys);
  }
  long long ans = 0;
  long long h = S.size();
  if (h > 0) {
    long long w = S[0].size();
    ans = h * w;
  }
  cout << ans << endl;
  return 0;
}
