// https://www.youtube.com/watch?v=nXr0mN-HyOA&t=8828s

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    A.at(i)--;
  }
  vector<vector<int> > is(N);
  for (int i = 0; i < N; i++) {
    is.at(A.at(i)).push_back(i);
  }

  // kが現れる場合の総数
  auto f = [&](vector<int> is) -> long long {
    long long ans = (long long)N * (N + 1) / 2;
    vector<int> nis(is);
    nis.push_back(N);
    int pi = -1;
    for (int i : nis) {
      int w = i - pi - 1;
      ans -= (long long)w * (w + 1) / 2;
      pi = i;
    }
    return ans;
  };
  long long ans = 0;
  for (int k = 0; k < N; k++) {
    ans += f(is.at(k));
  }
  for (int k = 0; k < N - 1; k++) {
    vector<int> nis(is.at(k));
    nis.insert(nis.begin(), is.at(k + 1).begin(), is.at(k + 1).end());
    sort(nis.begin(), nis.end());
    long long now = f(is.at(k)) + f(is.at(k + 1)) - f(nis);
    ans -= now;
  }
  cout << ans << endl;
  return 0;
}