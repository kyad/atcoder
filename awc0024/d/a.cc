#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N, W, K;
  cin >> N >> W >> K;
  vector<int> imos(N + 1, 0);
  for (int k = 0; k < K; k++) {
    int L;
    cin >> L;
    L--;
    imos.at(L)++;
    imos.at(L + W)--;
  }
  for (int i = 1; i <= N; i++) {
    imos.at(i) += imos.at(i - 1);
  }
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    ans.push_back(imos.at(i));
  }
  dump(ans);
  return 0;
}
