#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int> > a(N);
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    a.at(n) = make_pair(A, n);
  }
  sort(a.begin(), a.end());
  int ans = a.at(N - 2).second + 1;
  cout << ans << endl;
  return 0;
}
