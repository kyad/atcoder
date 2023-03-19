#include <algorithm>
#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(M);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  for (int m = 0; m < M; m++) {
    cin >> B.at(m);
  }
  // value, is_A, index(0-indexed)
  vector<tuple<int, bool, int> > C;
  for (int n = 0; n < N; n++) {
    C.push_back(make_tuple(A[n], true, n));
  }
  for (int m = 0; m < M; m++) {
    C.push_back(make_tuple(B[m], false, m));
  }
  sort(C.begin(), C.end());
  vector<int> ansA(N);
  vector<int> ansB(M);
  for (size_t i = 0; i < C.size(); i++) {
    bool is_a = get<1>(C[i]);
    int idx= get<2>(C[i]);
    if (is_a) {
      ansA[idx] = i + 1;
    } else {
      ansB[idx] = i + 1;
    }
  }
  for (int n = 0; n < N; n++) {
    cout << ansA[n] << " \n"[n == N - 1];
  }
  for (int m = 0; m < M; m++) {
    cout << ansB[m] << " \n"[m == M - 1];
  }
  return 0;
}
