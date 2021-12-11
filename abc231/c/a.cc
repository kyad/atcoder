#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  map<int, int> mp;
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    mp[A]++;
  }
  int prev;
  for (map<int, int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++) {
    if (it != mp.rbegin()) {
      it->second += prev;
    }
    prev = it->second;
  }
  for (int q = 0; q < Q; q++) {
    int x;
    cin >> x;
    int temp = mp.lower_bound(x)->second;
    cout << temp <<endl;
  }
  return 0;
}
