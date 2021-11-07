#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  for (int n = 0; n < N; n++) {
    cin >> x.at(n) >> y.at(n);
  }
  set<pair<int, int> > st;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int dx, dy, g;
      dx = x[j] - x[i];
      dy = y[j] - y[i];
      g = __gcd(dx, dy);
      dx /= g;
      dy /= g;
      st.insert(make_pair(dx, dy));
      st.insert(make_pair(-dx, -dy));
    }
  }
  cout << st.size() << endl;
  return 0;
}
