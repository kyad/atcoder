#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<set<int> > st(M);
  for (int n = 0; n < N; n++) {
    int A, B;
    cin >> A >> B;
    A--; B--;
    st[A].insert(n);
    st[B].insert(n);
  }
  vector<int> f(M + 2, 0);
  int right = 1;  // 開区間
  map<int, int> count;
  vector<int> added(M + 1, false);
  for (int left = 0; left < M; left++) {
    while (right <= M && count.size() < N) {
      if (!added[right - 1]) {
        for (set<int>::iterator it = st[right - 1].begin(); it != st[right - 1].end(); it++) {
          count[*it]++;
        }
        added[right - 1] = true;
      }
      if (count.size() == N) {
        break;
      }
      right++;
    }
    if (count.size() == N) {
      int mn = right - left;
      int mx = M - left;
      f[mn]++;
      f[mx + 1]--;
    }
    for (set<int>::iterator it = st[left].begin(); it != st[left].end(); it++) {
      count[*it]--;
      if (count[*it] <= 0) {
        count.erase(*it);
      }
    }
  }
  for (int m = 0; m <= M; m++) {
    f[m + 1] += f[m];
  }
  for (int m = 1; m < M + 1; m++) {
    cout << f[m];
    if (m == M) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
  return 0;
}
