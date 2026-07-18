#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long f(int M, vector<long long> A, vector<long long> B, int add0) {
  int N = A.size();
  long long ans = add0;
  A.at(0) += add0;
  for (int i = 1; i < N; i++) {
    if ((A.at(i) + A.at(i - 1)) % 2 == B.at(i - 1)) {
    } else {
      A.at(i)++;
      ans++;
    }
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<long long> A(N), B(N - 1);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N - 1; i++) {
    cin >> B.at(i);
  }
  long long ans1 = f(M, A, B, 0);
  long long ans2 = f(M, A, B, 1);
  long long ans = min(ans1, ans2);
  cout << ans << '\n';
  return 0;
}
