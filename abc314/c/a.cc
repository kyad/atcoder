#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<char> shift(vector<char> S) {
  vector<char> T;
  int N = S.size();
  if (N <= 1) {
    T = S;
  } else {
    T.push_back(S.at(N - 1));
    for (int n = 0; n <= N - 2; n++) {
      T.push_back(S.at(n));
    }
  }
  assert(S.size() == T.size());
  return T;
}

int main() {
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  vector<int> C(N);
  for (int n = 0; n < N; n++) {
    cin >> C.at(n);
    C.at(n)--;
  }
  vector<vector<char> > substr(M);
  for (int n = 0; n < N; n++) {
    substr[C[n]].push_back(S[n]);
  }
  vector<vector<char> > substr2(M);
  for (int m = 0; m < M; m++) {
    substr2[m] = shift(substr[m]);
  }
  string ans;
  vector<int> is(M, 0);
  for (int n = 0; n < N; n++) {
    int m = C.at(n);
    int i = is.at(m);
    ans.push_back(substr2[m][i]);
    is.at(m)++;
  }
  cout << ans << endl;
  return 0;
}
