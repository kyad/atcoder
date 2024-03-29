#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

template<class T> struct binary_indexed_tree {
  int N;
  vector<T> bit;  // 1-indexed
  binary_indexed_tree() {}
  binary_indexed_tree(int n) : N(n) {
    bit.resize(N + 1, 0);
  }
  void resize(int n) {
    N = n;
    bit.resize(N + 1, 0);
  }
  // Add x to a[k], O(logN)
  // k: 1-indexed
  void add1(int k, T x) {
    for (; k <= N; k += (k & -k)) {
      bit[k] += x;
    }
  }
  // Add x to a[k], O(logN)
  // k: 0-indexed
  void add0(int k, T x) {
    add1(k + 1, x);
  }
  // Returns a[1] + a[2] + ... + a[k], O(logN)
  // k: 1-indexed
  T sum1(int k) {
    T ret = 0;
    for (; k > 0; k -= (k & -k)) {
      ret += bit[k];
    }
    return ret;
  }
  // Returns a[0] + a[1] + ... + a[k], O(logN)
  // k: 0-indexed
  T sum0(int k) {
    return sum1(k + 1);
  }
  // Returns minimum x such that a[1] + a[2] + ... + a[x] >= w, O(logN)
  // return: 1-indexed (0: not found)
  T lower_bound1(T w) {
    if (w <= 0) {
      return 0;
    } else {
      T x = 0;
      int r = 1;
      while (r < N) {
        r = r << 1;
      }
      for (int len = r; len > 0; len = len >> 1) {
        if (x + len < N && bit[x + len] < w) {
          w -= bit[x + len];
          x += len;
        }
      }
      return x + 1;
    }
  }
  // return: 0-indexed (-1: not found)
  T lower_bound0(T w) {
    return lower_bound1(w) - 1;
  }
};

// Argument: A: 0-indexed, combination of {0, 1, 2, ..., N - 1} (Duplicated OK)
// Return value: Inversion number of A
// Use long long bit, because N=10^5 requires long long bit
// O(N log N)
template<class T> long long inversion_number_compressed(vector<T> A) {
  int N = A.size();
  binary_indexed_tree<long long> bit(N);
  long long ans = 0;
  for (int j = 0; j < N; j++) {
    ans += j - bit.sum0(A[j]);
    bit.add0(A[j], 1);
  }
  return ans;
}

// Compress A.
// Argument: A (input, output) 0-indexed array.
// O(N log N)
template<class T> void compress(vector<T>& A) {
  map<T, int> mp;
  for (size_t i = 0; i < A.size(); i++) {
    mp[A[i]]++;
  }
  int count = 0;
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
    it->second = count++;
  }
  for (size_t i = 0; i < A.size(); i++) {
    A[i] = mp[A[i]];
  }
}

// Argument: A: 0-indexed array. A might not be a permutation of {0, 1, 2, ..., N - 1}
// Return value: Inversion number of array A
// O(N log N)
template<class T> long long inversion_number(vector<T> A) {
  vector<T> B(A);
  compress(B);
  return inversion_number_compressed(B);
}

int main() {
  string S;
  cin >> S;
  map<char, int> mp;
  mp['a'] = 0;
  mp['t'] = 1;
  mp['c'] = 2;
  mp['o'] = 3;
  mp['d'] = 4;
  mp['e'] = 5;
  mp['r'] = 6;
  vector<int> A(7);
  for (int i = 0; i < 7; i++) {
    A.at(i) = mp[S[i]];
  }
  long long ans = inversion_number(A);
  cout << ans << endl;
  return 0;
}
