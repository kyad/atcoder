#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> st;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    st.insert(A);
  }
  vector<int> B;
  for (int a : st) {
    B.push_back(a);
  }
  reverse(B.begin(), B.end());
  cout << B.at(1) << endl;
  return 0;
}
