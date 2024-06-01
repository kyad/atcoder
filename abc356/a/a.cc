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
  for (int i = 1; i < L; i++) {
    ans.push_back(i);
  }
  for (int i = R; i >= L; i--) {
    ans.push_back(i);
  }
  for (int i = R + 1; i <= N; i++) {
    ans.push_back(i);
  }
  dumpvec(ans);
  return 0;
}
