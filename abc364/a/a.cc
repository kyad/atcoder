#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sweet = 0;
  int eat = 0;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    eat++;
    if (S == "sweet") {
      sweet++;
      if (sweet >= 2) {
        break;
      }
    } else {
      sweet = 0;
    }
  }
  bool ans = (eat == N);
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
