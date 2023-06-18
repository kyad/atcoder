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

int middle(vector<int> js) {
  assert(js.size() == 3);
  sort(js.begin(), js.end());
  return js[1];
}

int main() {
  int N;
  cin >> N;
  vector<vector<int> > js(N);
  for (int j = 0; j < N * 3; j++) {
    int A;
    cin >> A;
    A--;
    js.at(A).push_back(j);
  }
  vector<pair<int, int> > f;
  for (int n = 0; n < N; n++) {
    int mid = middle(js[n]);
    f.push_back(make_pair(mid, n));
  }
  sort(f.begin(), f.end());
  vector<int> ans(N);
  for (int n = 0; n < N; n++) {
    ans[n] = f[n].second + 1;
  }
  dumpvec(ans);
  return 0;
}
