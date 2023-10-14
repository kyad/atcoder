#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  string T;
  cin >> T;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  int L = T.size();

  // Tの頭から何個一致しているか
  auto f = [&](const string &S, const string &T) {
    int M = S.size();
    int i = 0;
    int j = 0;
    while (j < L) {
      if (S.at(i) == T.at(j)) {
        i++;
        j++;
      } else {
        i++;
      }
      if (i >= M) {
        break;
      }
    }
    return j;
  };

  // count[j]: 一致の合計がjの個数(0<=j<=L)
  vector<int> count(L + 1, 0);
  for (int n = 0; n < N; n++) {
    int now = f(S.at(n), T);
    assert(0 <= now);
    assert(now <= L);
    count[now]++;
  }
  // 累積和
  for (int j = L - 1; j >= 0; j--) {
    count[j] += count[j + 1];
  }

  long long ans = 0;
  reverse(T.begin(), T.end());
  for (int n = 0; n < N; n++) {
    reverse(S.at(n).begin(), S.at(n).end());
    int j = f(S.at(n), T);
    int jj = L - j;
    long long now = count.at(jj);
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
