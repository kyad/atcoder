#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  sort(A.begin(), A.end());
  vector<long long> sum(N);
  sum[0] = A[0];
  for (int n = 1; n < N; n++) {
    sum[n] += sum[n - 1] + A[n];
  }
  vector<pair<long long, int> > pos(N), neg(N);
  for (int n = 0; n < N; n++) {
    pos.at(n) = make_pair(A.at(n), n);
    neg.at(n) = make_pair(-A.at(n), -n);
  }
  sort(neg.begin(), neg.end());
  const int INF = 200001;
  for (int q = 0; q < Q; q++) {
    long long X;
    cin >> X;
    //cout << "----"<<endl;
    //cout << "X="<<X<<endl;
    long long ans = 0;
    vector<pair<long long, int> >::iterator it_l = upper_bound(pos.begin(), pos.end(), make_pair(X, INF));
    if (it_l != pos.end()) {
      int l = it_l->second;
      //cout << "l="<<l<<endl;
      int count = N - l;
      long long now;
      if (l == 0) {
        now = sum[N - 1] - X * count;
      } else {
        now = (sum[N - 1] - sum[l - 1]) - X * count;
      }
      //cout << "now="<<now<<endl;
      ans += now;
    }
    vector<pair<long long, int> >::iterator it_r = upper_bound(neg.begin(), neg.end(), make_pair(-X, 0));
    if (it_r != neg.end()) {
      int r = -it_r->second;
      //cout << "r="<<r<<endl;
      int count = r + 1;
      long long now = X * count - sum[r];
      //cout << "now="<<now<<endl;
      ans += now;
    }
    cout << ans << endl;
  }
  return 0;
}
