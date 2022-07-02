#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  long long X;
  cin >> N >> X;
  const long long INF = 3e18;
  vector<long long> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n) >> B.at(n);
  }
  vector<long long> S(N);
  for (int n = 0; n < N; n++) {
    S.at(n) = A.at(n) + B.at(n);
  }
  for (int n = 1; n < N; n++) {
    S.at(n) += S.at(n - 1);
  }
  vector<long long> time(N, INF);
  for (int n = 0; n < N; n++) {
    if (n + 1 > X) {
      break;
    }
    time[n] = S[n] + B[n] * (X - n - 1);
  }
  cout << *min_element(time.begin(), time.end()) << endl;
  return 0;
}
