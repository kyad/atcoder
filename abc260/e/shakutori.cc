// https://atcoder.jp/contests/abc260/tasks/abc260_e

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n) >> B.at(n);
    A.at(n)--; B.at(n)--;
  }
  vector<vector<int> > C(M);
  for (int n = 0; n < N; n++) {
    C.at(A.at(n)).push_back(n);
    C.at(B.at(n)).push_back(n);
  }
  map<int, int> mp;
  vector<int> f(M + 2, 0);
  int right = 0;
  for (int n : C.at(0)) {
    mp[n]++;
  }
  for (int left = 0; left < M; left++) {
    while (mp.size() < N && right < M - 1) {
      right++;
      for (int n : C.at(right)) {
        mp[n]++;
      }
    }
    if (mp.size() == N) {
      int mn = right - left + 1;
      int mx = M - left;
      f[mn]++;
      f[mx + 1]--;
    }
    for (int n : C.at(left)) {
      if (mp[n] >= 2) {
        mp[n]--;
      } else {
        mp.erase(n);
      }
    }
  }
  for (int m = 1; m < M; m++) {
    f.at(m + 1) += f.at(m);
  }
  for (int m = 1; m <= M; m++) {
    cout << f.at(m) << (m == M ? '\n' : ' ');
  }
  return 0;
}
