#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 4e18;

template<class T> bool chmax(T& a, const T b) { if (b > a) { a = b; return true; } else { return false; } }  // 更新した時にtrueを返す


int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    S.insert(S.begin(), '_');
    vector<long long> X(N + 1, 0), Y(N, 0);
    for (int i = 1; i <= N; i++) {
      cin >> X.at(i);
    }
    for (int i = 1; i <= N - 1; i++) {
      cin >> Y.at(i);
    }
    vector<long long> Z(N, 0);
    for (int i = 1; i <= N - 1; i++) {
      if (S.at(i) == 'R' && S.at(i + 1) == 'R') {
        Z.at(i) = -X.at(i + 1) + Y.at(i);
      } else if (S.at(i) == 'R' && S.at(i + 1) == 'S') {
        Z.at(i) = Y.at(i);
      } else if (S.at(i) == 'S' && S.at(i + 1) == 'R') {
        Z.at(i) = -X.at(i) -X.at(i + 1) + Y.at(i);
      } else {
        Z.at(i) = -X.at(i) + Y.at(i);
      }
    }
    vector<vector<long long>> dp(N, vector<long long>(2, -INF));
    dp.at(0).at(0) = 0;
    for (int i = 1; i <= N - 1; i++) {
      chmax(dp.at(i).at(0), dp.at(i - 1).at(0));
      chmax(dp.at(i).at(0), dp.at(i - 1).at(1));
      chmax(dp.at(i).at(1), dp.at(i - 1).at(0) + Z.at(i));
    }
    long long ans = max(dp.at(N - 1).at(0), dp.at(N - 1).at(1));
    cout << ans << '\n';
  }
  return 0;
}
