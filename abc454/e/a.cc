#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int ti = 0; ti < T; ti++) {
    int N, A, B;
    cin >> N >> A >> B;
    A--; B--;
    if (N % 2 == 1) {
      cout << "No\n";
      continue;
    } else if ((A + B) % 2 == 0) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    string S;
    for (int Y = 0; Y <= N - 2; Y += 2) {
      if (Y + 1 < A) {
        for (int i = 0; i < N - 1; i++) S.push_back('R');
        S.push_back('D');
        for (int i = 0; i < N - 1; i++) S.push_back('L');
        S.push_back('D');
      } else if (Y == A || Y + 1 == A) {
        vector<vector<bool> > visited(2, vector<bool>(N, false));
        visited.at(0).at(0) = true;
        visited.at(A - Y).at(B) = true;
        int y = 0;
        int x = 0;
        while (true) {
          if (visited.at(0).at(x) && visited.at(1).at(x)) {
            S.push_back('R'); x++;
          } else {
            if (y == 0) {
              S.push_back('D'); y++;
            } else {
              S.push_back('U'); y--;
            }
          }
          visited.at(y).at(x) = true;
          if (y == 1 && x == N - 1) {
            break;
          }
        }
      } else {
        S.push_back('D');
        for (int i = 0; i < N - 1; i++) S.push_back('L');
        S.push_back('D');
        for (int i = 0; i < N - 1; i++) S.push_back('R');
      }
    }
    cout << S << '\n';
  }
  return 0;
}
