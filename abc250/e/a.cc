#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1, 0), B(N + 1, 0);
  for (int n = 1; n <= N; n++) {
    cin >> A.at(n);
  }
  for (int n = 1; n <= N; n++) {
    cin >> B.at(n);
  }
  int Q;
  cin >> Q;
  // ans[x][y] = Yes/No
  map<int, map<int, bool> > ans;
  vector<int> QX(Q), QY(Q);
  for (int q = 0; q < Q; q++) {
    int qx, qy;
    cin >> qx >> qy;
    ans[qx][qy] = false;
    QX.at(q) = qx;
    QY.at(q) = qy;
  }
  set<int> S, T;
  int x = 1;
  int y = 1;
  // 長さnの場合をチェック
  for (int n = 1; n <= N; n++) {
    if (x > N) {
      continue;
    }
    if (y > N) {
      continue;
    }
    S.insert(A[x]);
    T.insert(B[y]);
    set<int> X, Y;
    X.insert(x);
    Y.insert(y);
    while (true) {
      if (x + 1 > N) {
        break;
      }
      if (S.count(A[x + 1]) > 0) {
        X.insert(x + 1);
        x++;
      } else {
        break;
      }
    }
    while (true) {
      if (y + 1 > N) {
        break;
      }
      if (T.count(B[y + 1]) > 0) {
        Y.insert(y + 1);
        y++;
      } else {
        break;
      }
    }
    if (S == T) {
      for (set<int>::iterator it = X.begin(); it != X.end(); it++) {
        int qx = *it;
        if (ans.count(qx) > 0) {
          for (map<int, bool>::iterator j = ans[qx].begin(); j != ans[qx].end(); j++) {
            if (Y.count(j->first) > 0) {
              j->second = true;
            }
          }
        }
      }
    }
    x++;
    y++;
  }
  for (int q = 0; q < Q; q++) {
    int qx = QX.at(q);
    int qy = QY.at(q);
    cout << (ans[qx][qy] ? "Yes" : "No") << endl;
  }
  return 0;
}
