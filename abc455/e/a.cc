#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long comb2(long long N) { return N * (N - 1) / 2; }

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  S.insert(S.begin(), '_');
  vector<int> A(N + 1, 0), B(N + 1, 0), C(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    if (S.at(i) == 'A') A.at(i)++;
    else if (S.at(i) == 'B') B.at(i)++;
    else C.at(i)++;
  }
  for (int i = 1; i <= N; i++) {
    A.at(i) += A.at(i - 1);
    B.at(i) += B.at(i - 1);
    C.at(i) += C.at(i - 1);
  }
  // A==B==Cの個数
  long long abc = 0;
  {
    map<pair<int, int>, int> count;
    for (int i = 0; i <= N; i++) {
      count[make_pair(A.at(i) - B.at(i), A.at(i) - C.at(i))]++;
    }
    for (auto [key, cnt]: count) {
      abc += comb2(cnt);
    }
  }
  // A==Bの個数
  long long ab = 0;
  {
    map<int, int> count;
    for (int i = 0; i <= N; i++) {
      count[A.at(i) - B.at(i)]++;
    }
    for (auto [key, cnt]: count) {
      ab += comb2(cnt);
    }
  }
  // B==Cの個数
  long long bc = 0;
  {
    map<int, int> count;
    for (int i = 0; i <= N; i++) {
      count[B.at(i) - C.at(i)]++;
    }
    for (auto [key, cnt]: count) {
      bc += comb2(cnt);
    }
  }
  // C==Aの個数
  long long ca = 0;
  {
    map<int, int> count;
    for (int i = 0; i <= N; i++) {
      count[C.at(i) - A.at(i)]++;
    }
    for (auto [key, cnt]: count) {
      ca += comb2(cnt);
    }
  }
  long long ans = (long long)N * (N + 1) / 2;
  ans = ans - ab - bc - ca + abc * 2;
  cout << ans << '\n';
  return 0;
}
