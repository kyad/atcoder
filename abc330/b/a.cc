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
  int N, L, R;
  cin >> N >> L >> R;
  vector<int> ans;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    int now = clamp(A, L, R);
    ans.push_back(now);
  }
  dumpvec(ans);
  return 0;
}
