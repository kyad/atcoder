#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    long long now = 1LL<<i;
    now *= (S.at(i) - 'a');
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
