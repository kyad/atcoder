#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int> > A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i + 1;
  }
  sort(A.begin(), A.end());
  cout << A[N - 2].second << endl;
  return 0;
}
