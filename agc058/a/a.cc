#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(2 * N + 1, -1);
  for (int n = 1; n <= 2 * N; n++) {
    cin >> P.at(n);
  }
  set<int> st;
  for (int x = 1; x <= 2 * N - 1; x += 2) {
    if (P[x] > P[x + 1]) {
      st.insert(x);
      swap(P[x], P[x + 1]);
    }
  }
  for (int x = 2; x <= 2 * N - 2; x += 2) {
    if (P[x] < P[x + 1]) {
      if (st.count(x + 1) > 0) {
        st.erase(x + 1);
        swap(P[x + 1], P[x + 2]);
      }
      st.insert(x);
      swap(P[x], P[x + 1]);
    }
  }
  int K = st.size();
  cout << K << endl;
  int k = 0;
  for (set<int>::iterator it = st.begin(); it != st.end(); it++) {
    cout << *it;
    if (k == K - 1) {
      cout << endl;
    } else {
      cout << ' ';
    }
    k++;
  }
  return 0;
}
