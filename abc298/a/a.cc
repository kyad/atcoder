#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  bool good = false;
  bool ng = false;
  for (int n = 0; n < N; n++) {
    if (S[n] == 'o') {
      good = true;
    } else if (S[n] == 'x') {
      ng = true;
    }
  }
  bool ans = good && (ng == false);
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
