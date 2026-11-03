#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N, K;
  long long P;
  cin >> N >> K >> P;
  vector<pair<long long, long long>> BA(N);
  for (int i = 0; i < N; i++) {
    cin >> BA.at(i).second >> BA.at(i).first;
  }
  sort(BA.begin(), BA.end());
  long long sum = 0;
  multiset<long long> ms;
  for (int i = 0; i < N; i++) {
    long long A = BA.at(i).second;
    long long B = BA.at(i).first;
    if ((int)ms.size() < K) {
      ms.insert(A);
      sum += A;
    } else {
      sum -= *ms.begin();
      ms.erase(ms.begin());
      ms.insert(A);
      sum += A;
    }
    if ((int)ms.size() < K) {
      continue;
    }
    if (sum >= P) {
      cout << B << '\n';
      exit(0);
    }
  }
  cout << -1 << '\n';
  return 0;
}
