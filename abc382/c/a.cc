#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  vector<int> B(M);
  for (int j = 0; j < M; j++) {
    cin >> B.at(j);
  }

  vector<pair<int, int> > bs(M);
  for (int j = 0; j < M; j++) {
    bs.at(j) = make_pair(B.at(j), j);
  }
  sort(bs.begin(), bs.end());

  vector<int> ans(M, -1);
  for (int i = 0; i < N; i++) {
    int a = A.at(i);
    auto start = lower_bound(bs.begin(), bs.end(), make_pair(a, -1));
    for (auto it = start; it < bs.end(); it++) {
      int j = it->second;
      if (ans.at(j) != -1) {
        break;
      } else {
        ans.at(j) = i + 1;
      }
    }
  }

  for (int j = 0; j < M; j++) {
    cout << ans.at(j) << '\n';
  }

  return 0;
}
