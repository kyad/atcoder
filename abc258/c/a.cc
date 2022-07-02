#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  int start = 0;
  for (int q = 0; q < Q; q++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      start += (N - x);
      start %= N;
    } else {
      x--;
      int pos = (x + start) % N;
      cout << S[pos] << endl;
    }
  }
  return 0;
}
