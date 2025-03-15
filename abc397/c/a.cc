#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  auto f = [&]() -> vector<int> {
    set<int> st;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
      st.insert(A.at(i));
      S.at(i) = st.size();
    }
    return S;
  };
  vector<int> S = f();
  reverse(A.begin(), A.end());
  vector<int> T = f();
  reverse(T.begin(), T.end());
  vector<int> U(N - 1);
  for (int i = 0; i < N - 1; i++) {
    U.at(i) = S.at(i) + T.at(i + 1);
  }
  int ans = *max_element(U.begin(), U.end());
  cout << ans << endl;
  return 0;
}
