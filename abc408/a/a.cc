#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    cin >> T.at(i);
  }
  bool ans = true;
  int last = 0;
  for (int i = 0; i < N; i++) {
    int now = T.at(i) - last;
    if (now > S) {
      ans = false;
    }
    last = T.at(i);
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
