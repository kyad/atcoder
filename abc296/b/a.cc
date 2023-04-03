#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 8;
  for (int y = 0; y < N; y++) {
    string S;
    cin >> S;
    for (int x = 0; x < N; x++) {
      if (S[x] == '*') {
        char c = ('a' + x);
        cout << c;
        int r = 8 - y;
        cout << r << endl;
        return 0;
      }
    }
  }
  return 1;
}
