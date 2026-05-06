#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  long long ans = 0;
  for (int d = 1; d <= N - 1; d++) {
    vector<int> is;
    is.push_back(-1);
    for (int i = 0; i < N - d; i++) {
      if (S.at(i) != S.at(i + d)) {
        is.push_back(i);
      }
    }
    is.push_back(N - d);
    long long now = 0;
    int M = is.size();
    for (int i = 1; i <= M - 2; i++) {
      long long left = is.at(i) - is.at(i - 1);
      long long right = is.at(i + 1) - is.at(i);
      now += left * right;
    }
    ans += now;
  }
  cout << ans << '\n';
  return 0;
}
