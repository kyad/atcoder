#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  long long sum =  0;
  map<int, int> count;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    count[A]++;
    sum += A;
  }
  vector<long long> B;
  for (auto [a, cnt]: count) {
    long long now = (long long) a * cnt;
    B.push_back(now);
  }
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  int M = B.size();
  for (int j = 0; j < min(M, K); j++) {
    sum -= B.at(j);
  }
  cout << sum << '\n';
  return 0;
}
