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
  vector<vector<vector<int> > > S(N, vector<vector<int> >(N));
  S[0][0].push_back(A[0][0]);
  for (int k = 1; k <= N - 2; k++) {
    for (int i = 0; i <= k - 1; i++) {
      int j = k - 1 - i;
      // i, jからの遷移
      const int di[2] = {1, 0};
      const int dj[2] = {0, 1};
      for (int l = 0; l < 2; l++) {
        int ni = i + di[l];
        int nj = j + dj[l];
        for (auto s : S[i][j]) {
          S[ni][nj].push_back(s ^ A[ni][nj]);
        }
      }
    }
  }

  vector<vector<vector<int> > > T(N, vector<vector<int> >(N));
  T[N - 1][N - 1].push_back(A[N - 1][N - 1]);
  for (int k = 1; k <= N - 1; k++) {
    for (int i = N - 1; i >= N - k; i--) {
      int j = 2 * N - 1 - k - i;
      // i, jからの遷移
      const int di[2] = {-1, 0};
      const int dj[2] = {0, -1};
      for (int l = 0; l < 2; l++) {
        int ni = i + di[l];
        int nj = j + dj[l];
        for (auto t : T[i][j]) {
          T[ni][nj].push_back(t ^ A[ni][nj]);
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
      map<int, int> mpS, mpT;
      for (int t : T[i][j]) {
        mpT[t]++;
        st.insert(t);
      }
      for (int s : S[ni][nj]) {
        mpS[s]++;
        st.insert(s);
      }
      for (int i : st) {
        long long cntS = mpS[i];
        long long cntT = mpT[i];
        ans += cntS * cntT;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
