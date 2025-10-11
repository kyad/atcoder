#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  string ans;
  for (int i = 0; i < N; i++) {
    if (i * 2 + 1 == N) {
      continue;
    }
    ans.push_back(S.at(i));
  }
  cout << ans << endl;
  return 0;
}
