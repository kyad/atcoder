#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int f = 0;
  for (int n = 0; n < N; n++) {
    string S;
    cin >> S;
    if (S == "For") {
      f++;
    }
  }
  bool ans = (f >= N / 2 + 1);
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
