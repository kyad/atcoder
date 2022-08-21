#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  long long T;
  cin >> N >> M >> T;
  vector<long long> A(N - 1);
  for (int n = 0; n < N - 1; n++) {
    cin >> A.at(n);
  }
  vector<long long> Y(N, 0);
  for (int m = 0; m < M; m++) {
    int x;
    long long y;
    cin >> x >> y;
    x--;
    Y[x] = y;
  }
  bool ans = false;
  for (int n = 0; n < N; n++) {
    if (n == N - 1) {
      ans = true;
      break;
    }
    T += Y[n];
    T -= A[n];
    if (T <= 0) {
      break;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
