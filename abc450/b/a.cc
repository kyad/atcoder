#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > C(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      cin >> C.at(i).at(j);
      C.at(j).at(i) = C.at(i).at(j);
    }
  }
  bool ans = false;
  for (int a = 0; a < N; a++) {
    for (int b = a + 1; b < N; b++) {
      for (int c = b + 1; c < N; c++) {
        if (C.at(a).at(c) > C.at(a).at(b) + C.at(b).at(c)) {
          ans = true;
        }
      }
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
