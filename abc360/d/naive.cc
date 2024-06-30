#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int naive() {
  int N;
  long long T;
  cin >> N >> T;
  string S;
  cin >> S;
  vector<long long> X(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i);
  }
  vector<int> lefts, rights;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '0') {
      lefts.push_back(i);  // 左に進む
    } else {
      rights.push_back(i);
    }
  }
  long long ans = 0;
  for (int i : rights) {
    long long x = X[i];
    for (int j : lefts) {
      long long y = X[j];
      if (x < y && (y - x) <= 2 * T) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

int main() {
  naive();
  return 0;
}
