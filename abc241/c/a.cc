#include <iostream>
#include <vector>
using namespace std;

// vector
template<class T> ostream& operator<<(ostream& os, const vector<T> &v) {
  size_t N = v.size();
  int MOD = -1;
  os << '[';
  for (size_t i = 0; i < N; i++) {
    os << v[i];
    if (i == N - 1) {
      continue;
    } else if (MOD > 0 && i % MOD == (MOD - 1)) {
      os << '\n';
    } else {
      os << ' ';
    }
  }
  os << ']';
  return os;
}


int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int n = 0; n < N; n++) {
    cin >> S.at(n);
  }
  bool ok = false;
  // yoko
  for (int y = 0; y < N; y++) {
    vector<int> A(N + 1, 0);
    for (int n = 1; n <= N; n++) {
      int x = n - 1;
      if (S[y][x] == '#') {
        A[n] = 1;
      } else {
        A[n] = 0;
      }
    }
    for (int n = 1; n <= N; n++) {
      A[n] += A[n - 1];
    }
    for (int n = 6; n <= N; n++) {
      int count = A[n] - A[n - 6];
      if (count >= 4) {
        ok = true;
      }
    }
  }
  // tate
  for (int x = 0; x < N; x++) {
    vector<int> A(N + 1, 0);
    for (int n = 1; n <= N; n++) {
      int y = n - 1;
      if (S[y][x] == '#') {
        A[n] = 1;
      } else {
        A[n] = 0;
      }
    }
    for (int n = 1; n <= N; n++) {
      A[n] += A[n - 1];
    }
    for (int n = 6; n <= N; n++) {
      int count = A[n] - A[n - 6];
      if (count >= 4) {
        ok = true;
      }
    }
  }
  // naname
  vector<int> A(1003, 0);
  vector<int> B(1003, 0);
  for (int k = 0; k < 2; k++) {
    for (int x0 = -(N - 6); x0 <= (N - 6); x0++) {
      int m = 0; // B_size
      for (int y = 0; y < N; y++) {
        int x = y + x0;
        if (x < 0 || x >= N) {
          continue;
        }
        int xx;
        if (k == 0) {
          xx = x;
        } else {
          xx = N - x - 1;
        }
        if (S[y][xx] == '#') {
          B[m] = 1;
        } else {
          B[m] = 0;
        }
        m++;
      }
      if (m < 6) {
        continue;
      }
      A[0] = 0;
      for (int i = 0; i < m; i++) {
        A[i + 1] = B[i];
      }
      for (int n = 1; n <= m; n++) {
        A[n] += A[n - 1];
      }
      for (int n = 6; n <= m; n++) {
        int count = A[n] - A[n - 6];
        if (count >= 4) {
          ok = true;
        }
      }
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}

