#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> L(N);
  vector<vector<int> > X(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
    for (int j = 0; j < L.at(i); j++) {
      int x;
      cin >> x;
      X.at(i).push_back(x);
    }
  }
  vector<bool> used(M + 1, false);
  vector<int> ans(N, 0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < L.at(i); j++) {
      if (!used.at(X.at(i).at(j))){
        ans.at(i) = X.at(i).at(j);
        used.at(X.at(i).at(j)) = true;
        break;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans.at(i) << '\n';
  }
  return 0;
}
