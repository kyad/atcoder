#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int H, W, RS, CS;
  cin >> H >> W >> RS >> CS;
  int N;
  cin >> N;
  map<int, vector<int> > A, B;
  for (int n = 0; n < N; n++) {
    int r, c;
    cin >> r >> c;
    A[c].push_back(r);
    B[r].push_back(c);
  }
  const int INF = 1e9+2;
  map<int, vector<int> > A2, B2;
  for (map<int, vector<int> >::iterator it = A.begin(); it != A.end(); it++) {
    it->second.push_back(INF);
    it->second.push_back(-INF);
    sort(it->second.begin(), it->second.end());
    for (int x : it->second) {
      A2[it->first].push_back(-x);
    }
    sort(A2[it->first].begin(), A2[it->first].end());
  }
        
  for (map<int, vector<int> >::iterator it = B.begin(); it != B.end(); it++) {
    it->second.push_back(INF);
    it->second.push_back(-INF);
    sort(it->second.begin(), it->second.end());
    for (int x : it->second) {
      B2[it->first].push_back(-x);
    }
    sort(B2[it->first].begin(), B2[it->first].end());
  }

  int Q;
  cin >> Q;
  int r = RS;
  int c = CS;
  for (int q = 0; q < Q; q++) {
    char d;
    int l;
    cin >> d >> l;
    if (d == 'R') {
      if (B.count(r) > 0) {
        c = min(*lower_bound(B[r].begin(), B[r].end(), c) - 1, c + l);
      } else {
        c += l;
      }
      c = min(c, W);
    } else if (d == 'L') {
      if (B2.count(r) > 0) {
        c = max(-(*lower_bound(B2[r].begin(), B2[r].end(), -c)) + 1, c - l);
      } else {
        c -= l;
      }
      c = max(c, 1);
    } else if (d == 'D') {
      if (A.count(c) > 0) {
        r = min(*lower_bound(A[c].begin(), A[c].end(), r) - 1, r + l);
      } else {
        r += l;
      }
      r = min(r, H);
    } else {  // U
      if (A2.count(c) > 0) {
        r = max(-(*lower_bound(A2[c].begin(), A2[c].end(), -r)) + 1, r - l);
      } else {
        r -= l;
      }
      r = max(r, 1);
    }
    cout << r << ' ' << c << '\n';
  }
  return 0;
}
