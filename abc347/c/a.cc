#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  long long A, B;
  cin >> N >> A >> B;
  const long long W = A + B;
  vector<int> D(N);
  for (int i = 0; i < N; i++) {
    cin >> D[i];
  }
  set<long long> st;
  for (int i = 0; i < N; i++) {
    st.insert(D[i] % W);
  }
  vector<long long> E;
  for (long long e : st) {
    E.push_back(e);
  }
  int M = E.size();

  for (int start = 0; start < M; start++) {
    int last = (start + M - 1) % M;
    bool now = ((E[last] - E[start] + W) % W) < A;
    if (now) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
