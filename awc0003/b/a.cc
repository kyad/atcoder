#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  vector<char> L(N), R(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i) >> R.at(i);
  }
  for (int i = 0; i < N - 1; i++) {
    if (R.at(i) == L.at(i + 1)) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
