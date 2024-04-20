#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
    A.at(n)--;
  }
  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    P.at(A.at(i)) = i;
  }
  vector<pair<int, int> > ans;
  for (int a = 0; a < N; a++) {
    int b = A.at(a);
    int p = P.at(a);
    if (a != p) {
      ans.emplace_back(a + 1, p + 1);
    }
    swap(A.at(a), A.at(p));
    swap(P.at(a), P.at(b));
  }
  int K = ans.size();
  assert(K <= N - 1);
  cout << K << '\n';
  for (int i = 0; i < K; i++) {
    cout << ans.at(i).first << ' ' << ans.at(i).second << '\n';
  }
  return 0;
}
