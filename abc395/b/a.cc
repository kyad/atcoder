#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> S(N, string(N, '0'));
  auto fill = [&](int i, int j, char c) {
    for (int y = i; y <= j; y++) {
      for (int x = i; x <= j; x++) {
        S.at(y).at(x) = c;
      }
    }
  };
  for (int i = 0; i < N; i++) {
    int j = N - 1 - i;
    if (i > j) {
      continue;
    }
    char c;
    if (i % 2 == 0) {
      c = '#';
    } else {
      c = '.';
    }
    fill(i, j, c);
  }
  for (int i = 0; i < N; i++) {
    cout << S.at(i) << '\n';
  }
  return 0;
}
