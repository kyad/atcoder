#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(N);
  for (int i = 0; i < N; i++) {
    int L;
    cin >> L;
    for (int j = 0; j < L; j++) {
      int a;
      cin >> a;
      A.at(i).push_back(a);
    }
  }
  int X, Y;
  cin >> X >> Y;
  int ans = A.at(X - 1).at(Y - 1);
  cout << ans << '\n';
  return 0;
}
