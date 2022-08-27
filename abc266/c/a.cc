#include <iostream>
#include <vector>
using namespace std;

template<class T> T outprod2(T ax, T ay, T bx, T by) {
  return ax * by - ay * bx;
}

int main() {
  vector<int> X(4), Y(4);
  for (int n = 0; n < 4; n++) {
    cin >> X.at(n) >> Y.at(n);
  }
  for (int i = 0; i < 4; i++) {
    int j = (i + 1) % 4;
    int k = (j + 1) % 4;
    int ax = X[j] - X[i];
    int ay = Y[j] - Y[i];
    int bx = X[k] - X[j];
    int by = Y[k] - Y[j];
    int op = outprod2(ax, ay, bx, by);
    if (op < 0) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
