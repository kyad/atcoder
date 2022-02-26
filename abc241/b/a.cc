#include <iostream>
#include <map>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  map<int, int> A;
  for (int n = 0; n < N; n++) {
    int a;
    cin >> a;
    A[a]++;
  }
  bool ok = true;
  for (int m = 0; m < M; m++) {
    int b;
    cin >> b;
    if (A[b] > 0) {
      A[b]--;
    } else {
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
