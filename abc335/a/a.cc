#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int len = S.size();
  S[len-1] = '4';
  cout << S << endl;
  return 0;
}
