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
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  vector<pair<int, int> > win(N);
  for (int n = 0; n < N; n++) {
    win[n].first = count(S[n].begin(), S[n].end(), 'o');
    win[n].second = -n;
  }
  sort(win.rbegin(), win.rend());
  vector<int> ans(N);
  for (int n = 0; n < N; n++) {
    ans[n] = -win[n].second + 1;
  }
  dumpvec(ans);
  return 0;
}
