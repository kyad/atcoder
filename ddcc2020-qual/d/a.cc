// https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d

#include <iostream>
using namespace std;

int main() {
  int M;
  cin >> M;
  long long D = 0;
  long long S = 0;
  for (int m = 0; m < M; m++) {
    int d;
    long long c;
    cin >> d >> c;
    D += c;
    S += c * d;
  }
  // 桁1個毎に答えを1増やす
  // 左から足していって、10以上になるたびに9減らして答えを1増やす
  long long ans = (long long)(D - 1) + (long long)((S - 1) / 9);
  cout << ans << endl;
  return 0;
}
