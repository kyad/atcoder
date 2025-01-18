#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  int shift = 0;
  vector<pair<long long, long long> > q;
  long long prev = 0;
  long long sum = 0;
  for (int qi = 0; qi < Q; qi++) {
    int type;
    cin >> type;
    if (type == 1) {
      int l;
      cin >> l;
      q.push_back(make_pair(prev, l));
      prev += l;
    } else if (type == 2) {
      sum += q.at(shift).second;
      shift++;
    } else {
      int k;
      cin >> k;
      k--;
      long long ans = q.at(shift + k).first - sum;
      cout << ans << '\n';
    }
  }
  return 0;
}
