#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n) >> B.at(n);
  }
  multiset<pair<int, int> > st;
  for (int n = 0; n < N; n++) {
    const int diff = B.at(n) - A.at(n);
    st.insert(make_pair(diff, n));
  }
  vector<int> is_front(N, true);
  long long ans = 0;
  for (int n = 0; n < N; n++) {
    {
      // Alice
      int diff = st.begin()->first;
      int i = st.begin()->second;
      is_front[i] = !is_front[i];
      st.erase(st.find(make_pair(diff, i)));
      st.insert(make_pair(-diff, i));
    }
    {
      // Bob
      int diff = st.begin()->first;
      int i = st.begin()->second;
      if (is_front[i]) {
        ans += A[i];
      } else {
        ans += B[i];
      }
      st.erase(st.find(make_pair(diff, i)));
    }
  }
  cout << ans << endl;
  return 0;
}
