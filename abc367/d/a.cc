#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  int M;
  cin >> N >> M;
  vector<long long> A(2 * N + 1, 0);
  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    A.at(i) = a;
    A.at(i + N) = a;
  }
  vector<long long> S(2 * N + 1, 0);
  for (int i = 1; i <= 2 * N; i++) {
    S.at(i) = S.at(i - 1) + A.at(i);
  }
  vector<long long> R(M, 0);  // R[j]: 今見ている中のうち、Mで割った余りがjの個数
  for (int i = 1; i <= N - 2; i++) {
    R.at(S.at(i) % M)++;
  }
  // メイン
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    R.at(S.at(i + N - 2) % M)++;
    long long now = R.at(S.at(i - 1) % M);
    ans += now;
    R.at(S.at(i) % M)--;
  }
  cout << ans << endl;
  return 0;
}
