#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  long long X;
  cin >> X;
  long long S = 0;
  for (int n = 0; n < N; n++) {
    S += (long long)A.at(n);
  }
  long long K = X / S;
  X %= S;
  int k;
  long long sum = 0;
  for (k = 0; k < N; k++) {
    if (sum > X) {
      break;
    }
    sum += (long long)A.at(k);
  }
  cout << K * N + k << endl;
  return 0;
}
