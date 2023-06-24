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
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    int now = 0;
    for (int j = 0; j < 7; j++) {
      int A;
      cin >> A;
      now += A;
    }
    ans.push_back(now);
  }
  dumpvec(ans);
  return 0;
}
