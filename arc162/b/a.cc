#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> P.at(n);
  }
  vector<pair<int, int> > ans;
  for (int n = 1; n <= N; n++) {
    if (n == N - 1) {
      if (P[n] == N - 1) {
        cout << "Yes" << endl;
        int M = ans.size();
        cout << M << '\n';
        for (size_t k = 0; k < ans.size(); k++) {
          cout << ans[k].first << ' ' << ans[k].second << '\n';
        }
      } else {
        cout << "No" << endl;
      }
      break;
    }
    // nを合わせる
    if (P[n] == n) {
      continue;
    }

    auto f = [&](int i, int j) {
      // P --> R
      vector<int> R;
      R.push_back(0);  // 1-indexed
      for (int k = 1; k <= j; k++) {
        R.push_back(P.at(k));
      }
      for (int k = 0; k < 2; k++) {
        R.push_back(P.at(i + k));
      }
      for (int k = j + 1; k <= N; k++) {
        if (k == i || k == i + 1) {
          continue;
        }
        R.push_back(P.at(k));
      }
      swap(P, R);
      assert((int)P.size() == N + 1);
    };

    int i = find(P.begin(), P.end(), n) - P.begin();
    if (i == N) {
      f(N - 1, n - 1);
      ans.push_back(make_pair(N - 1, n - 1));
      i = find(P.begin(), P.end(), n) - P.begin();
    }
    assert(1 <= i && i <= N - 1);
    const int j = n - 1;
    assert(0 <= j && j <= N - 2);
    ans.push_back(make_pair(i, j));
    f(i, j);
  }
  return 0;
}
