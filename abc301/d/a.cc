#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int M = S.size();
  long long s = 0;
  for (int i = 0; i < M; i++) {
    if (S[i] == '1') {
      s |= (1LL<<(M - i - 1));
    }
  }

  long long N;
  cin >> N;
  long long ans = 0;
  if (s <= N) {
    ans = s;
  } else {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < M; i++) {
    long long b = 1LL<<(M - i - 1);
    if (S[i] != '?') {
      continue;
    }
    
    if (ans + b <= N) {
      ans += b;
    }
  }
  cout << ans << endl;
  return 0;
}
