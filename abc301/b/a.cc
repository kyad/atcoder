#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// vectorを1行で表示する
template<class T> void dumpvec(const vector<T>& A) {
  int N = A.size();
  for (int n = 0; n < N; n++) {
    cout << A.at(n) << " \n"[n + 1 == N];
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> ans;
  ans.push_back(A[0]);
  for (int n = 0; n < N - 1; n++) {
    if (A[n] < A[n + 1]) {
      for (int a = A[n] + 1; a <= A[n + 1]; a++) {
        ans.push_back(a);
      }
    } else {
      for (int a = A[n] - 1; a >= A[n + 1]; a--) {
        ans.push_back(a);
      }
    }
  }
  dumpvec(ans);
  return 0;
}
