#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<string> a;
  a.push_back("N");
  a.push_back("NE");
  a.push_back("E");
  a.push_back("SE");
  a.push_back("S");
  a.push_back("SW");
  a.push_back("W");
  a.push_back("NW");
  string D;
  cin >> D;
  int i;
  int N = 8;
  for (i = 0; i < N; i++) {
    if (D == a.at(i)) {
      break;
    }
  }
  assert(i < N);
  string ans = a.at((i + 4) % N);
  cout << ans << endl;
  return 0;
}
