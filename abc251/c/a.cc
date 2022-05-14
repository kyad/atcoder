#include <iostream>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<tuple<string, int, bool> > data(N);
  set<string> st;
  for (int n = 0; n < N; n++) {
    string S;
    int T;
    cin >> S;
    cin >> T;
    get<0>(data.at(n)) = S;
    get<1>(data.at(n)) = T;
    if (st.count(S) > 0) {
      get<2>(data.at(n)) = false;
    } else {
      get<2>(data.at(n)) = true;
    }
    st.insert(S);
  }
  int ans = -1;
  int max = -1;
  for (int n = 0; n < N; n++) {
    int T = get<1>(data.at(n));
    bool is_original = get<2>(data.at(n));
    if (!is_original) {
      continue;
    }
    if (T > max) {
      max = T;
      ans = n;
    }
  }
  ans++;
  cout << ans << endl;
  return 0;
}
