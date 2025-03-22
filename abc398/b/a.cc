#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 7;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    A.at(i)--;
  }

  bool ans = false;
  // next_combination(N, r)
  vector<int> mask(N, 1);
  int r = 5;
  for (int i = 0; i < N - r; i++) {
    mask.at(i) = 0;
  }
  do {
    vector<int> count(13, 0);
    for (int i = 0; i < N; i++) {
      if (mask.at(i)) {
        // Do something
        count.at(A.at(i))++;
      }
    }
    for (int i = 0; i < 13; i++) {
      for (int j = 0; j < 13; j++) {
        if (i == j) {
          continue;
        }
        if (count.at(i) == 3 && count.at(j) == 2) {
          ans = true;
        }
      }
    }
  } while (next_permutation(mask.begin(), mask.end()));
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}
