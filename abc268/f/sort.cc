#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long score(const string& T) {
  long long ans = 0;
  long long x = 0;
  for (size_t i = 0; i < T.size(); i++) {
    if (T[i] == 'X') {
      x++;
    } else {
      ans += x * (T[i] - '0');
    }
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  auto comp = [](const string& a, const string& b) {
    return score(a + b) > score(b + a);
  };
  sort(S.begin(), S.end(), comp);
  string T;
  for (string s : S) {
    T += s;
  }
  cout << score(T) << endl;
  return 0;
}
