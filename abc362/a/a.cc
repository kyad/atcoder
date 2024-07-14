#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int R, G, B;
  cin >> R >> G >> B;
  string C;
  cin >> C;
  int ans;
  if (C == "Red") {
    ans = min(G, B);
  } else if (C == "Green") {
    ans = min(R, B);
  } else {
    ans = min(R, G);
  }
  cout << ans << endl;
  return 0;
}
