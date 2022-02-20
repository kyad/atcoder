#include <iostream>
#include <stack>
using namespace std;

int main() {
  int N;
  cin >> N;
  stack<pair<int, int> > st;
  int ans = 0;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    ans += 1;
    int remove = 0;
    // simulate
    if (st.empty()) {
      st.push(make_pair(A, 1));
    } else {
      int number = st.top().first;
      int count = st.top().second;
      if (number == A) {
        st.pop();
        if (count + 1 >= number) {
          remove = number;
        } else {
          st.push(make_pair(number, count + 1));
        }
      } else {
        st.push(make_pair(A, 1));
      }
    }
    ans -= remove;
    cout << ans << endl;
  }
  return 0;
}
