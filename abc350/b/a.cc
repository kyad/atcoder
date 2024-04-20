#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> tooth(N, 1);
  for (int q = 0; q < Q; q++) {
    int T;
    cin >> T;
    T--;
    tooth.at(T) = 1 - tooth.at(T);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += tooth.at(i);
  }
  cout << ans << endl;
  return 0;
}
