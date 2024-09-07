#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > A(N, vector<int>(N, -1));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> A.at(i).at(j);
      A.at(i).at(j)--;
    }
  }
  int i = 0;
  for (int j = 0; j < N; j++) {
    if (i >= j) {
      i = A.at(i).at(j);
    } else {
      i = A.at(j).at(i);
    }
  }
  int ans = i + 1;
  cout << ans << endl;
  return 0;
}
