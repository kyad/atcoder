#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int f(const vector<int>& L, int R) {
  int N = L.size();
  int ans = R;

  int lenl = 0;
  for (int i = 0; i <= R - 1; i++) {
    if (L.at(i) == 1) {
      lenl++;
    } else {
      break;
    }
  }
  ans -= lenl;

  int count0 = 0;
  for (int i = lenl; i <= R - 1; i++) {
    if (L.at(i) == 1) {
      count0++;
    }
  }
  ans += count0;

  ans += (N - R);

  int lenr = 0;
  for (int i = N - 1; i >= R; i--) {
    if (L.at(i) == 1) {
      lenr++;
    } else {
      break;
    }
  }
  ans -= lenr;

  int count1 = 0;
  for (int i = N - 1 - lenr; i >= R; i--) {
    if (L.at(i) == 1) {
      count1++;
    }
  }
  ans += count1;

  return ans;
}

int main() {
  int N, R;
  cin >> N >> R;
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
  }
  int ans0 = f(L, R);
  reverse(L.begin(), L.end());
  int ans1 = f(L, N - R);
  int ans = min(ans0, ans1);

  cout << ans << endl;
  return 0;
}
