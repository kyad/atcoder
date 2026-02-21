#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    int x = A[i];
    chmax(mp[x], mp[x - 1] + 1);
  }
  int ans = 0;
  for (auto [key, value]: mp) {
    chmax(ans, value);
  }
  cout << ans << '\n';
  return 0;
}
