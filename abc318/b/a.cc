#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<bool> > P(100, vector<bool>(100, false));
  for (int i = 0; i < N; i++) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    for (int x = A; x < B; x++) {
      for (int y = C; y < D; y++) {
        P.at(y).at(x) = true;
      }
    }
  }
  int S = 0;
  for (int x = 0; x < 100; x++) {
    for (int y = 0; y < 100; y++) {
      if (P.at(y).at(x) == true) {
        S++;
      }
    }
  }
  cout << S << endl;
  return 0;
}
