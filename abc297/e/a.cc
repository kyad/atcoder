#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  set<long long> st;
  for (int n = 0; n < N; n++) {
    st.insert(A.at(n));
  }
  for (int k = 1; k <= K; k++) {
    long long now = *st.begin();
    if (k == K) {
      cout << now << endl;
      break;
    }
    st.erase(now);
    for (int n = 0; n < N; n++) {
      st.insert(now + A.at(n));
    }
  }
  return 0;
}
