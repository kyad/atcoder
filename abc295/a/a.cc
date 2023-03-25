#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool ans = false;
  for (int n = 0; n < N; n++) {
    string S;
    cin >> S;
    if (S == "and" || S == "not" || S == "that" || S == "the" || S == "you") {
      ans = true;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
