#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long naive(int N, const vector<int>& A) {
  long long ans = 0;
  for (int l = 0; l < N / 2; l++) {
    int r = N - 1 - l;
    if (A[l] != A[r]) {
      ans++;
    }
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    int a;
    cin >> a;
    A.at(n) = a;
  }
  long long ans = 0;
  for (int l = 0; l < N; l++) {
    for (int r = l; r < N; r++) {
      vector<int> B;
      for(int i = l; i <= r; i++) {
        B.push_back(A[i]);
      }
      int M = B.size();
      long long now = naive(M, B);
      ans += now;
    }
  }
  cout << ans << endl;
  return 0;
}
