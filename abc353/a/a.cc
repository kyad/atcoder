#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  int i;
  for (i = 1; i < N; i++) {
    if (H.at(i) > H.at(0)) {
      break;
    }
  }
  int ans;
  if (i == N) {
    ans = -1;
  } else {
    ans = i + 1;
  }
  cout << ans << endl;
  return 0;
}
