#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  set<int> st;
  for (int i = 0; i < N; i++) {
    if (A.at(i) <= W) {
      st.insert(A.at(i));
    }
    for (int j = i + 1; j < N; j++) {
      int sum = A.at(i) + A.at(j);
      if (sum <= W) {
        st.insert(sum);
      }
      for (int k = j + 1; k < N; k++) {
        int sum = A.at(i) + A.at(j) + A.at(k);
        if (sum <= W) {
          st.insert(sum);
        }
      }
    }
  }
  cout << st.size() << endl;
  return 0;
}
