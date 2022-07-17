#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, X, Y, Z;
  cin >> N >> X >> Y >> Z;
  vector<int> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }
  vector<bool> selected(N, false);
  // 1
  vector<pair<int, int> > a(N);
  for (int n = 0; n < N; n++) {
    a.at(n) = make_pair(-A.at(n), n);
  }
  sort(a.begin(), a.end());
  int x = 0;
  for (int n = 0; n < N; n++) {
    int i = a.at(n).second;
    if (x < X && !selected.at(i)) {
      selected.at(i) = true;
      x++;
    }
  }
  // 2
  vector<pair<int, int> > b(N);
  for (int n = 0; n < N; n++) {
    b.at(n) = make_pair(-B.at(n), n);
  }
  sort(b.begin(), b.end());
  int y = 0;
  for (int n = 0; n < N; n++) {
    int i = b.at(n).second;
    if (y < Y && !selected.at(i)) {
      selected.at(i) = true;
      y++;
    }
  }
  // 3
  vector<pair<int, int> > c(N);
  for (int n = 0; n < N; n++) {
    c.at(n) = make_pair(-(A.at(n) + B.at(n)), n);
  }
  sort(c.begin(), c.end());
  int z = 0;
  for (int n = 0; n < N; n++) {
    int i = c.at(n).second;
    if (z < Z && !selected.at(i)) {
      selected.at(i) = true;
      z++;
    }
  }
  for (int n = 0; n < N; n++) {
    if (selected.at(n)) {
      cout << (n + 1) << endl;
    }
  }
  return 0;
}
