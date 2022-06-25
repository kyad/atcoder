// https://atcoder.jp/contests/abc257/tasks/abc257_e

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> C(10);
  const int INF = 1000001;
  C.at(0) = INF;
  for (int i = 1; i <= 9; i++) {
    cin >> C.at(i);
    C.at(0) = min(C.at(0), C.at(i));
  }
  int D = N / C.at(0);
  for (int i = 1; i <= 9; i++) {
    C.at(i) -= C.at(0);
  }
  int res = N - C.at(0) * D;
  for (int d = 0; d < D; d++) {
    int now = 0;
    for (int x = 1; x <= 9; x++) {
      if (C.at(x) <= res) {
        now = x;
      }
    }
    cout << now;
    res -= C.at(now);
  }
  cout << endl;
  return 0;
}
