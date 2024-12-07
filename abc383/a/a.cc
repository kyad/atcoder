#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int S = 0;
  int prevT = 0;
  for (int i = 0; i < N; i++) {
    int T, V;
    cin >> T >> V;
    S -= (T - prevT);
    S = max(0, S);
    S += V;
    prevT = T;
  }
  cout << S << endl;
  return 0;
}
