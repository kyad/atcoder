#include <iostream>
#include <vector>
using namespace std;

// 000??????000??000
bool solve0(int N, int K, string S) {
  int count = 0;
  int len = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '?') {
      len++;
    } else {
      if (len == K) {
        count++;
      } else if (len > K) {
        return false;
      }
      len = 0;
    }
  }
  if (len == K) {
    count++;
  } else if (len > K) {
    return false;
  }
  return (count == 1);
}

bool testcase(int N, int K, string S) {
  int l = -1;
  for (int n = 0; n < N; n++) {
    if (S[n] == '1') {
      l = n;
      break;
    }
  }
  int r = N;
  for (int n = N - 1; n >= 0; n--) {
    if (S[n] == '1') {
      r = n;
      break;
    }
  }
  if (l < 0 || r >= N) {
    // No 1
    return solve0(N, K, S);
  }
  // l..r check
  bool ok = true;
  for (int i = l; i <= r; i++) {
    if (S[i] == '0') {
      ok = false;
      break;
    }
  }
  if (!ok) {
    return false;
  }
  // a, b, c
  int a = r - l + 1;
  int b = 0;
  for (int i = l - 1; i >= 0; i--) {
    if (S[i] == '?') {
      b++;
    } else {
      break;
    }
  }
  int c = 0;
  for (int i = r + 1; i <= N - 1; i++) {
    if (S[i] == '?') {
      c++;
    } else {
      break;
    }
  }
  bool ans;
  if (b == 0) {
    if (a <= K && K <= a + c) {
      ans = true;
    } else {
      ans = false;
    }
  } else if (c == 0) {
    if (a <= K && K <= a + b) {
      ans = true;
    } else {
      ans = false;
    }
  } else {
    if (a == K || (a + b + c) == K) {
      ans = true;
    } else {
      ans = false;
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    bool ans = testcase(N, K, S);
    cout << (ans ? "Yes" : "No") << endl;
  }
  return 0;
}
