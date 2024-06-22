#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > is(N);
  for (int i = 0; i < 2 * N; i++) {
    int A;
    cin >> A;
    A--;
    is.at(A).push_back(i);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int d = is.at(i).at(1) - is.at(i).at(0);
    if (d == 2) ans++;
  }
  cout << ans << endl;
  return 0;
}
