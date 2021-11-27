#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<pair<int, int> > C(N);
  for (int n = 0; n < N; n++) {
    int A, B;
    cin >> A >> B;
    C.at(n) = make_pair(A, B);
  }
  sort(C.begin(), C.end(), greater<pair<int, int> >());
  long long ans = 0;
  for (int n = 0; n < N; n++) {
    int a = C[n].first;
    int b = C[n].second;
    int w = min(W, b);
    ans += (long long)a * w;
    W -= w;
    if (W == 0) {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
