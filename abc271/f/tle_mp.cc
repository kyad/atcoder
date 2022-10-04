#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int> > A(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A.at(i).at(j);
    }
  }
  vector<vector<map<int, long long> > > S(N, vector<map<int, long long> >(N));
  S[0][0][A[0][0]] = 1;
  for (int k = 1; k <= N - 2; k++) {
    for (int i = 0; i <= k - 1; i++) {
      int j = k - 1 - i;
      // i, jからの遷移
      const int di[2] = {1, 0};
      const int dj[2] = {0, 1};
      for (int l = 0; l < 2; l++) {
        int ni = i + di[l];
        int nj = j + dj[l];
        for (auto [s, c] : S[i][j]) {
          S[ni][nj][s ^ A[ni][nj]] += c;
        }
      }
    }
  }

  vector<vector<map<int, long long> > > T(N, vector<map<int, long long> >(N));
  T[N - 1][N - 1][A[N - 1][N - 1]] = 1;
  for (int k = 1; k <= N - 1; k++) {
    for (int i = N - 1; i >= N - k; i--) {
      int j = 2 * N - 1 - k - i;
      // i, jからの遷移
      const int di[2] = {-1, 0};
      const int dj[2] = {0, -1};
      for (int l = 0; l < 2; l++) {
        int ni = i + di[l];
        int nj = j + dj[l];
        for (auto [t, c] : T[i][j]) {
          T[ni][nj][t ^ A[ni][nj]] += c;
        }
      }
    }
  }

  long long ans = 0;
  for (int i = 0; i <= N - 1; i++) {
    int j = N - 1 - i;
    // T(i, j)からの遷移
    const int di[2] = {-1, 0};
    const int dj[2] = {0, -1};
    for (int l = 0; l < 2; l++) {
      int ni = i + di[l];
      int nj = j + dj[l];
      if (ni < 0 || nj < 0) {
        continue;
      }
      set<int> st;
      for (auto [t, ct] : T[i][j]) {
        st.insert(t);
      }
      for (auto [s, ct] : S[ni][nj]) {
        st.insert(s);
      }
      for (int value : st) {
        ans += S[ni][nj][value] * T[i][j][value];
      }
    }
  }
  cout << ans << endl;
  return 0;
}
