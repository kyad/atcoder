#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, T, P;
  cin >> N >> T >> P;
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
  }
  auto check = [&]() {
    int count = 0;
    for (int i = 0; i < N; i++) {
      if (L.at(i) >= T) {
        count++;
      }
    }
    return count >= P;
  };
  int ans = 0;
  for (int i = 0; i < 105; i++) {
    if (check()) {
      break;
    }
    ans++;
    for (int j = 0; j < N; j++) {
      L.at(j)++;
    }
  }
  cout << ans << endl;
  return 0;
}
