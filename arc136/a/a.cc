#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  string ans;
  int a = 0;
  int b = 0;
  auto append = [&]() {
    for (int i = 0; i < a + b / 2; i++) {
      ans.push_back('A');
    }
    for (int i = 0; i < b % 2; i++) {
      ans.push_back('B');
    }
    // Reset
    a = 0;
    b = 0;
  };
  for (int n = 0; n < N; n++) {
    if (S[n] == 'A') {
      a++;
    } else if (S[n] == 'B') {
      b++;
    } else {
      append();
      ans.push_back(S[n]);
    }
  }
  append();
  cout << ans << endl;
  return 0;
}
