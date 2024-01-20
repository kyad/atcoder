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
    if (A.at(n) > 0) {
      A.at(n)--;
    }
  }
  int start = -1;
  vector<int> nx(N, -1);
  for (int i = 0; i < N; i++) {
    if (A[i] == -1) {
      start = i;
    } else {
      nx.at(A.at(i)) = i;
    }
  }
  vector<int> s;
  int now = start;
  while (now >= 0) {
    s.push_back(now + 1);
    now = nx.at(now);
  }
  dumpvec(s);
  return 0;
}
