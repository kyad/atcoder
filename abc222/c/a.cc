#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(vector<int> win) {
  vector<pair<int, int> > temp(win.size());
  for (size_t i = 0; i < win.size(); i++) {
    temp[i] = make_pair(-win[i], i);
  }
  sort(temp.begin(), temp.end());
  vector<int> ans(win.size());
  for (size_t i = 0; i < win.size(); i++) {
    ans[i] = temp[i].second;
  }
  return ans;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> A(2 * N);
  for (int n = 0; n < 2 * N; n++) {
    cin >> A[n];
  }
  vector<int> win(2 * N, 0);
  for (int m = 0; m < M; m++) {
    vector<int> rank = solve(win);
    for (int n = 0; n < N; n++) {
      int a = rank[2 * n];
      int b = rank[2 * n + 1];
      if ((A[a][m] == 'G' && A[b][m] == 'C')
          || (A[a][m] == 'C' && A[b][m] == 'P')
          || (A[a][m] == 'P' && A[b][m] == 'G')) {
        win[a]++;
      } else if ((A[b][m] == 'G' && A[a][m] == 'C')
          || (A[b][m] == 'C' && A[a][m] == 'P')
          || (A[b][m] == 'P' && A[a][m] == 'G')) {
        win[b]++;
      }
    }
  }
  vector<int> rank = solve(win);
  for (int n = 0; n < 2 * N; n++) {
    cout << (rank[n] + 1) << endl;
  }
  return 0;
}
