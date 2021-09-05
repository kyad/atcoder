// https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_b

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long dp[2000][2000];
long long A[2000];

// Returns maximum size when IOI-chan select from begin to end
long long rec(int N, int begin, int end) {
  if (dp[begin][end] >= 0) {
    return dp[begin][end];
  }
  if (begin == end) {
    dp[begin][end] = 0;
    return dp[begin][end];
  } else if ((end - begin + N) % N == 1) { // begin + 1 == end
    dp[begin][end] = min(A[begin], A[end]);
    return dp[begin][end];
  }
  int begin2, end2;
  if (A[end] < A[begin]) {
    begin2 = (begin + 1) % N;
    end2 = end; 
  } else if (A[end] > A[begin]) {
    begin2 = begin;
    end2 = (end - 1 + N) % N;
  } else {
    cout << "Error" << endl;
    exit(1);
  }
  dp[begin][end] = max(A[begin2] + rec(N, (begin2 + 1) % N, end2),
                       A[end2] + rec(N, begin2, (end2 - 1 + N) % N));
  return dp[begin][end];
}

int main() {
  int N;
  cin >> N;
  for (int n = 0; n < N; n++) {
    cin >> A[n];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -1;
    }
  }
  vector<long long> opt(N);
  for (int n = 0; n < N; n++) {
    int begin = (n + 1) % N;
    int end = (n - 1 + N) % N;
    opt[n] = A[n] + rec(N, begin, end);
  }
  cout << *max_element(opt.begin(), opt.end()) << endl;
  return 0;
}
