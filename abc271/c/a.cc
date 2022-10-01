#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A;
  const int INF = 1000000001;
  set<int> st;
  for (int n = 0; n < N; n++) {
    int a;
    cin >> a;
    if (st.count(a) == 0) {
      A.push_back(a);
      st.insert(a);
    }
  }
  int M = N - A.size();
  for (int m = 0; m < M; m++) {
    A.push_back(INF);
  }
  sort(A.begin(), A.end());
  int l = 0;
  int r = N - 1;
  int ans = 0;
  while (l <= r) {
    if (A.at(l) == ans + 1) {
      ans++;
      l++;
      continue;
    }
    if (r - l >= 1) {
      ans++;
      r -= 2;
      continue;
    }
    break;
  }
  cout << ans << endl;
  return 0;
}
