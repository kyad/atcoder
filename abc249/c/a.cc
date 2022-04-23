#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  int ans = 0;
  for (int b = 0; b < (1<<N); b++) {
    vector<int> count(26, 0);
    for (int n = 0; n < N; n++) {
      if ((b>>n)&1) {
        for (size_t i = 0; i < S.at(n).size(); i++) {
          count[S.at(n).at(i) - 'a']++;
        }
      }
    }
    int now = 0;
    for (int c = 0; c < 26; c++) {
      if (count[c] == K) {
        now++;
      }
    }
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}
