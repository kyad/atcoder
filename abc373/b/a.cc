#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ans = 0;
  int N = S.size();
  vector<int> pos(26, -1);
  for (int i = 0; i < N; i++) {
    int c = S[i] - 'A';
    pos[c] = i;
  }
  for (int i = 0; i < 25; i++) {
    int a = pos[i];
    int b = pos[i + 1];
    ans += abs(a - b);
  }
  cout << ans << endl;
  return 0;
}
