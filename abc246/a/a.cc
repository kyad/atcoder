#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int, int> X;
  map<int, int> Y;
  for (int i = 0; i < 3; i++) {
    int x, y;
    cin >> x >> y;
    X[x]++;
    Y[y]++;
  }
  int ax = 0, ay = 0;
  for (map<int, int>::iterator it = X.begin(); it != X.end(); it++) {
    if (it->second == 1) {
      ax = it->first;
    }
  }
  for (map<int, int>::iterator it = Y.begin(); it != Y.end(); it++) {
    if (it->second == 1) {
      ay = it->first;
    }
  }
  cout << ax << ' ' << ay << endl;
  return 0;
}
