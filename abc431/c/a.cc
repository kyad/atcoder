#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H.at(i);
  }
  multiset<int> st;
  for (int j = 0; j < M; j++) {
    int B;
    cin >> B;
    st.insert(B);
  }
  sort(H.begin(), H.end());
  if (N < K) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < K; i++) {
    auto it = st.lower_bound(H.at(i));
    if (it == st.end()) {
      cout << "No" << endl;
      return 0;
    }
    st.erase(it);
  }
  cout << "Yes" << endl;
  return 0;
}
