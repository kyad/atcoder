#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N), B(N);
  vector<int> ans(N, -1);
  vector<pair<long long, int>> P;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
    if (A.at(i) + B.at(i) >= K) {
      P.push_back(make_pair(-A.at(i) - B.at(i), i));
    }
  }
  sort(P.begin(), P.end());
  int idx = 1;
  for (auto [_, i] : P) {
    ans.at(i) = idx;
    idx++;
  }
  for (int i = 0; i < N; i++)  {
    cout << ans.at(i) << '\n';
  }
  return 0;
}
