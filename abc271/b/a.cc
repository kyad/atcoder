#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<int> > A(N);
  for (int n = 0; n < N; n++) {
    int L;
    cin >> L;
    vector<int> now(L);
    for (int l = 0; l < L; l++) {
      cin >> now.at(l);
    }
    A.at(n) = now;
  }
  for (int q = 0; q < Q; q++) {
    int s, t;
    cin >> s >> t;
    cout << A.at(s - 1).at(t - 1) << endl;
  }
  return 0;
}
