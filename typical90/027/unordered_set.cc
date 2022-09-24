#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  int N;
  cin >> N;
  unordered_set<string> st;
  for (int n = 0; n < N; n++) {
    string S;
    cin >> S;
    if (st.count(S) == 0) {
      cout << (n + 1) << endl;
      st.insert(S);
    }
  }
  return 0;
}
