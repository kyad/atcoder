#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  int volume = 0;
  bool play = false;
  for (int qi = 0; qi < Q; qi++) {
    int A;
    cin >> A;
    if (A == 1) {
      volume++;
    } else if (A == 2) {
      if (volume >= 1) {
        volume--;
      }
    } else {
      play = !play;
    }
    bool ans = play && (volume >= 3);
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}
