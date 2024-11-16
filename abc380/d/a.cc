#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string S;
  cin >> S;
  int Q;
  cin >> Q;
  int N = S.size();
  for (int qi = 0; qi < Q; qi++) {
    long long K;
    cin >> K;
    K--;
    long long g = K / N;
    
    char c = S.at(K % N);
    if (__builtin_popcountll(g) % 2 == 1) {
      int diff = 'a' - 'A';
      if ('a' <= c && c <= 'z') {
        c -= diff;
      } else {
        c += diff;
      }
    }
    cout << c << " \n"[qi + 1 == Q];
  }
  return 0;
}
