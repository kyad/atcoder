#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int len = S.size();
  if (len % 5 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << '\n';
  }
  return 0;
}
