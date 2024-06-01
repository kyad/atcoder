#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int> > LR(N);
  for (int i = 0; i < N; i++) {
    cin >> LR.at(i).first >> LR.at(i).second;
  }
  sort(LR.begin(), LR.end());
  vector<int> Ls(N);
  for (int i = 0; i < N; i++) {
    Ls.at(i) = LR.at(i).first;
  }
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    int R = LR.at(i).second;
    long long now = upper_bound(Ls.begin() + i, Ls.end(), R) - (Ls.begin() + i) - 1;
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
