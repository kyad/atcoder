#include <iostream>
using namespace std;

string S;

string f(int L, int R) {
  string ans(S);
  for (int i = 0; i < R - L + 1; i++) {
    ans[L + i] = (S[R - i] == 'd' ? 'p' : 'd');
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  cin >> S;
  string ans = S;
  for (int L = 0; L < N; L++) {
    for (int R = L; R < N; R++) {
      ans = min(ans, f(L, R));
    }
  }
  cout << ans << endl;
  return 0;
}
