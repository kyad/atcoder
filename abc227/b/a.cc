#include <iostream>
#include <set>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> st;
  const int MAX = 997 / 7 + 1;
  for (int a = 1; a <= MAX; a++) {
    for (int b = 1; b <= MAX; b++) {
      int s = 4 * a * b + 3 * a + 3 * b;
      st.insert(s);
    }
  }
  int ans = 0;
  for (int n = 0; n < N; n++) {
    int S;
    cin >> S;
    if (st.count(S) == 0) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
