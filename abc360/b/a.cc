#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int N = S.size();
  bool ans = false;
  for (int w = 1; w < N; w++) {
    for (int c = 0; c < w; c++) {
      string now;
      for (int i = 0; i < N; i++) {
        if (i % w == c) {
          now.push_back(S.at(i));
        }
      }
      if (T == now) {
        ans = true;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
