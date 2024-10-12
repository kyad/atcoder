#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  long long ans = 0;
  for (char c = 'A'; c <= 'Z'; c++) {  // 両端の文字を固定する
    // 個数の累積和
    vector<long long> count(N, 0);
    for (int i = 0; i < N; i++) {
      count.at(i) = S.at(i) == c;
    }
    vector<long long> T(N, 0);  // T[i]: iまでのcの個数
    T.at(0) = count.at(0);
    for (int i = 1; i < N; i++) {
      T.at(i) = T.at(i - 1) + count.at(i);
    }
    vector<long long> U(N, 0);  // T[i]: iより右のcの個数
    U.at(N - 1) = count.at(N - 1);
    for (int i = N - 2; i >= 0; i--) {
      U.at(i) = U.at(i + 1) + count.at(i);
    }
    
    long long now = 0;
    for (int i = 1; i < N - 1; i++) {
      long long left = T.at(i - 1);
      long long right = U.at(i + 1);
      now += left * right;
    }
    ans += now;
  }
  cout << ans << endl;
  return 0;
}
