#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, D, V;
  cin >> N >> D >> V;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int S;
    cin >> S;
    if (S > V) {
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}
