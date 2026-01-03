#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long solve(const vector<int> &A) {
  int N = A.size();
  map<int, int> P, R;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) % 5 == 0) {
      int k = A.at(i) / 5;
      long long now = (long long)P[k] * R[k];
      ans += now;
    }
    if (A.at(i) % 7 == 0) {
      P[A.at(i) / 7]++;
    }
    if (A.at(i) % 3 == 0) {
      R[A.at(i) / 3]++;
    }
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  long long ans1 = solve(A);
  reverse(A.begin(), A.end());
  long long ans2 = solve(A);
  long long ans = ans1 + ans2;
  
  cout << ans << '\n';
  return 0;
}
