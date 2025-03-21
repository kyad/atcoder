#include <iostream>
#include <vector>

using namespace std;

vector<long long> digits(long long N) {
  vector<long long> ans;
  while (N > 0) {
    ans.push_back(N % 10);
    N /= 10;
  }
  return ans;
}

bool is_good(long long N) {
  long long sum = 0;
  for (long long d : digits(N)) {
    sum += d;
  }
  return N % sum == 0;
}

void naive(int N) {
  for (int a = N; a + 1 <= 2 * N; a++) {
    if (is_good(a) && is_good(a + 1)) {
      cout << a << endl;
      return;
    }
  }
  cout << -1 << endl;
}

int main_list() {
  for (int a = 1; a <= 10100; a++) {
    if (is_good(a) && is_good(a + 1)) {
      cout << a << endl;
    }
  }
  return 0;
}

int main() {
  string N;
  cin >> N;
  int K = N.size();
  if (K <= 2) {
    naive(stoi(N));
  } else {
    string b = N.substr(0, 3);
    int M = stoi(b);
    int ans;
    if (M <= 110) {
      ans = 110;
    } else if (M <= 200) {
      ans = 200;
    } else if (M <= 224) {
      ans = 224;
    } else if (M <= 440) {
      ans = 440;
    } else if (M <= 800) {
      ans = 800;
    } else {
      ans = 1100;
    }
    cout << ans;
    for (int k = 0; k < K - 3; k++) {
      cout << '0';
    }
    cout << endl;
  }
  return 0;
}
