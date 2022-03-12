#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int n = 0; n < N; n++) {
    cin >> A.at(n);
  }
  vector<int> B(N);
  for (int n = 0; n < N; n++) {
    cin >> B.at(n);
  }
  map<int, int> mp;
  int ans1 = 0;
  for (int n = 0; n < N; n++) {
    mp[A[n]]++;
    mp[B[n]]++;
    if (A[n] == B[n]) {
      ans1++;
    }
  }
  int ans2 = 0;
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    if (it->second == 2) {
      ans2++;
    }
  }
  ans2 -= ans1;
  cout << ans1 << endl;
  cout << ans2 << endl;
  return 0;
}
