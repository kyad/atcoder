#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<string> P(N);
  for (int n = 0; n < N; n++) {
    cin >> P.at(n);
  }
  // sum[i][j] = (0, 0)~(i, j)までのWの個数
  vector<vector<long long> > sum(N, vector<long long>(N, 0));
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (P[y][x] == 'B') {
        sum.at(y).at(x)++;
      }
    }
  }
  for (int y = 0; y < N; y++) {
    for (int x = 1; x < N; x++) {
      sum.at(y).at(x) += sum.at(y).at(x - 1);
    }
  }
  for (int x = 0; x < N; x++) {
    for (int y = 1; y < N; y++) {
      sum.at(y).at(x) += sum.at(y - 1).at(x);
    }
  }
  auto g = [&](int i, int j) -> long long {  // (0, 0)~(i-1, j-1)までのWの個数
    assert(0 <= i && i <= N);
    assert(0 <= j && j <= N);
    if (i == 0 || j == 0) {
      return 0;
    }
    return sum.at(i - 1).at(j - 1);
  };
  auto f = [&](int i, int j) -> long long {  // (0, 0)~(i-1, j-1)までのWの個数
    long long gy = i / N;
    long long gx = j / N;
    long long ans = gy * gx * g(N, N)
      + gx * g(i % N, N)
      + gy * g(N, j % N)
      + g(i % N, j % N);
    return ans;
  };
  for (int q = 0; q < Q; q++) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    long long ans = f(C + 1, D + 1) - f(C + 1, B) - f(A, D + 1) + f(A, B);
    cout << ans << '\n';
  }
  return 0;
}
