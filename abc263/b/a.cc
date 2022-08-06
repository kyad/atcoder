#include <iostream>
#include <vector>
using namespace std;

vector<int> P;

int f(int a) {
  if (a == 0) {
    return 0;
  }
  return f(P[a]) + 1;
}

int main() {
  int N;
  cin >> N;
  P.resize(N);
  for (int i = 1; i <= N - 1; i++) {
    cin >> P[i];
    P[i]--;
  }
  cout << f(N - 1) << endl;
  return 0;
}
