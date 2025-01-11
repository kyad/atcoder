#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  int MG;
  cin >> MG;
  vector<vector<bool> > G(N, vector<bool>(N, false));
  for (int m = 0; m < MG; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    G.at(U).at(V) = true;
    G.at(V).at(U) = true;
  }

  int MH;
  cin >> MH;
  vector<vector<bool> > H(N, vector<bool>(N, false));
  for (int m = 0; m < MH; m++) {
    int U, V;
    cin >> U >> V;
    U--; V--;
    H.at(U).at(V) = true;
    H.at(V).at(U) = true;
  }

  vector<vector<int> > A(N, vector<int>(N, 0));
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      cin >> A.at(i).at(j);
      A.at(j).at(i) = A.at(i).at(j);
    }
  }

  // 順列初期化
  vector<int> P(N, -1);
  for (int i = 0; i < N; i++) {
    P.at(i) = i;
  }
  // 順列全探索
  int ans = 1e9;
  do {
    int now = 0;
    for (int i = 0; i < N - 1; i ++) {
      for (int j = i + 1; j < N; j++) {
        if (H.at(i).at(j) != G.at(P.at(i)).at(P.at(j))) {
          now += A.at(i).at(j);
        }
      }
    }
    ans = min(ans, now);
  } while (next_permutation(P.begin(), P.end()));


  cout << ans << endl;
  return 0;
}
