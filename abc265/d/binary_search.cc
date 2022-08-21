#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long P, Q, R;
  cin >> N >> P >> Q >> R;
  vector<long long> A(N + 1, 0); // 1-indexed
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  vector<long long> S(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    S.at(n) = S.at(n - 1) + A.at(n);
  }
  for (int n = 0; n <= N; n++) {
    vector<long long> x(3, 0);
    x[0] = S.at(n) + P;
    x[1] = x[0] + Q;
    x[2] = x[1] + R;
    vector<bool> now(3, false);
    for (int i = 0; i < 3; i++) {
      now[i] = binary_search(S.begin(), S.end(), x[i]);
    }
    if ((now[0] == true) && (now[1] == true) && (now[2] == true)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
