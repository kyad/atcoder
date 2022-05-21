#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

long long comb2(int a) {
  long long temp = a;
  long long ans = temp * (temp - 1) / 2;
  return ans;
}

long long comb3(int a) {  // a <= 10^6
  long long temp = a;
  long long ans = temp * (temp - 1) * (temp - 2) / 6;
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<int> count(200001, 0);
  for (int n = 0; n < N; n++) {
    int A;
    cin >> A;
    count[A]++;
  }
  long long ans = comb3(N);
  for (int i = 1; i <= 200000; i++) {
    int c = count.at(i);
    if (c >= 3) {
      long long now = comb3(c);
      ans -= now;
    }
    if (c >= 2) {
      long long now = comb2(c) * (long long)(N - c);
      ans -= now;
    }
  }
  cout << ans << endl;
  return 0;
}
