#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> G(6);
  for (int i = 0; i < 6; i++) {
    cin >> G.at(i);
  }
  const int value[6] = {1, 5, 10, 50, 100, 500};
  int N;
  cin >> N;
  vector<int> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i);
  }
  for (int i = 5; i >= 0; i--) {
    while (G.at(i) > 0) {
      bool used = false;
      for (int j = 0; j < N; j++) {
        if (X.at(j) >= value[i]) {
          X.at(j) -= value[i];
          G.at(i)--;
          used = true;
          break;
        }
      }
      if (!used) {
        break;
      }
    }
  }
  bool ans = true;
  for (int j = 0; j < N; j++) {
    if (X.at(j) > 0) {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
