// https://atcoder.jp/contests/abc145/tasks/abc145_c

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

inline double distance(int x0, int y0, int x1, int y1) {
  return sqrt( ((x0 - x1) * (x0 - x1)) + ((y0 - y1) * (y0 - y1)) );
}

int main() {
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i) >> y.at(i);
  }
  vector<int> p(N);
  for (int i = 0; i < N; i++) {
    p.at(i) = i;
  }
  double sum = 0;
  int num = 0;
  do {
    double dist = 0;
    for (int i = 0; i < N - 1; i++) {
      dist += distance(x.at(p.at(i)), y.at(p.at(i)), x.at(p.at(i + 1)), y.at(p.at(i + 1)));
    }
    sum += dist;
    num++;
  } while (next_permutation(p.begin(), p.end()));
  printf("%lf\n", sum / num);
  return 0;
}
