#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
    A.at(n)--;
  }
  set<int> st;
  int a = X - 1;
  while (true) {
    if (st.count(a) > 0) {
      break;
    }
    st.insert(a);
    a = A[a];
  }
  cout << st.size() << endl;
  return 0;
}
