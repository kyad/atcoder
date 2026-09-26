#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> types(Q + 1);
  vector<int> Xs(Q + 1, -1);
  vector<char> Cs(Q + 1);
  int last2 = -1;
  for (int qi = 1; qi <= Q; qi++) {
    cin >> types.at(qi);
    if (types.at(qi) == 1) {
      cin >> Xs.at(qi);
      Xs.at(qi)--;
    } else {
      cin >> Cs.at(qi);
      last2 = qi;
    }
  }
  // 最後のtype=2以降は無視すれば良い
  if (last2 == -1) {
    string ans(N, 'a');
    cout << ans << endl;
    exit(0);
  }
  // type2が続いたら後者のみ残す
  for (int qi = 1; qi <= last2 - 1; qi++) {
    if (types.at(qi) == 2 && types.at(qi + 1) == 2) {
      types.at(qi) = 0;
    }
  }

  vector<bool> state(N, false); // タイルを置いた=true
  vector<int> last(N, -1);      // 最後にタイルを置いたタイミング
  vector<pair<int, char>> colors;
  // 前処理: type2間の同じtype1が2個以上あったら2個ペアで消す
  //unordered_map<int, vector<int>> events;
  unordered_map<int, vector<int>> events;
  for (int qi = 1; qi <= last2; qi++) {
    if (types.at(qi) == 2) {
      // 精算
      for (unordered_map<int, vector<int>>::iterator it = events.begin(); it != events.end(); it++) {
        int i = it->first;
        vector<int>& qs = it->second;
        if (qs.size() % 2 == 1) {
          if (state.at(i) == false) {  // タイルが置かれていない時
            last.at(i) = qs.at(0);
            state.at(i) = true;
          } else {  // タイルが置かれている時
            last.at(i) = -1;
            state.at(i) = false;
          }
        }
      }
      colors.push_back(make_pair(qi, Cs.at(qi)));
      events.clear();
    } else if (types.at(qi) == 1) {
      // eventsに積む
      int X = Xs.at(qi);
      events[X].push_back(qi);
    }
  }
  for (int i = 0; i < N; i++) {
    if (last.at(i) == -1) {
      last.at(i) = Q + 1;
    }
  }
  string ans(N, '_');
  for (int i = 0; i < N; i++) {
    int q = last.at(i);
    auto it = lower_bound(colors.begin(), colors.end(), make_pair(q, 'a' - 1));
    if (it == colors.begin()) {
      ans.at(i) = 'a';
    } else {
      ans.at(i) = prev(it)->second;
    }
  }
  cout << ans << '\n';
  return 0;
}
