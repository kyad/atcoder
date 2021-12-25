#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int L, R;
  cin >> L >> R;
  L--;
  R--;
  string S;
  cin >> S;
  string::iterator a = S.begin() + L;
  string::iterator b = S.begin() + R + 1;
  reverse(a, b);
  cout << S << endl;
  return 0;
}
