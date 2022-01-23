#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  set<string> st;
  for (int m = 0; m < M; m++) {
    string T;
    cin >> T;
    st.insert(T);
  }
  for (int n = 0; n < N; n++) {
    if (st.count(S.at(n)) > 0) {
      cout << "Yes" <<endl;
    } else {
      cout << "No" <<endl;
    }
  }
  return 0;
}
