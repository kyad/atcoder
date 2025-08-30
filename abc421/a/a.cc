#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  int X;
  string Y;
  cin >> X;
  cin >> Y;
  bool ans;
  if (S.at(X - 1) == Y) {
    ans = true;
  } else {
    ans = false;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
