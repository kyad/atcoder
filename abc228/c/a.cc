#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> S(N);
  for (int n = 0; n < N; n++) {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    S.at(n) = p1 + p2 + p3;
  }
  vector<int> T(N);
  for (int n = 0; n < N; n++) {
    T.at(n) = S.at(n);
  }
  sort(T.begin(), T.end(), greater<int>());
  int th = T[K - 1] - 300;
  for (int n = 0; n < N; n++) {
    if (S.at(n) >= th) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
