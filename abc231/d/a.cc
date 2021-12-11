#include <iostream>
#include <set>
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

// 2d-matrix
template<class T> ostream& operator<<(ostream& os, const vector<vector<T> > &v) {
  size_t y0 = 0;
  size_t y1 = v.size() - 1;
  for (size_t i = y0; i <= y1; i++) {
    os << (i == 0 ? "[[" : " [");
    size_t x0 = 0;
    size_t x1 = v[i].size() - 1;
    if (v[i].size() == 0) {
      continue;
    }
    for (size_t j = x0; j <= x1; j++) {
      os << v[i][j];
      if (j != x1) {
        os << ' ';
      }
    }
    os << (i == y1 ? "]]" : "]\n");
  }
  return os;
}

vector<vector<int> > graph;
vector<bool> visited;
bool dfs(int s, int parent) {
  if (visited[s]) {
    return false;
  }
  visited[s] = true;
  for (size_t i = 0; i < graph[s].size(); i++) {
    int v = graph[s][i];
    if (v == parent) {
      continue;
    }
    if (!dfs(v, s)) {
      return false;
    }
  }
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<set<int> > st(N);
  for (int m = 0; m < M; m++) {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    st.at(A).insert(B);
    st.at(B).insert(A);
  }
  graph.resize(N);
  for (int n = 0; n < N; n++) {
    for (set<int>::iterator it = st.at(n).begin(); it != st.at(n).end(); it++) {
      graph.at(n).push_back(*it);
    }
  }
  //cout<<"graph="<<graph<<endl;
  for (int n = 0; n < N; n++) {
    if (graph.at(n).size() > 2) {
      cout << "No" << endl;
      return 0;
    }
  }
  // DFS
  visited.assign(N, false);
  //cout<<"visited="<<visited<<endl;
  for (int n = 0; n < N; n++) {
    //cout<<"n="<<n<<endl;
    if (visited[n]) {
      continue;
    }
    if (!dfs(n, -1)) {
      cout << "No" << endl;
      return 0;
    }
    //cout<<"visited="<<visited<<endl;
  }
  cout << "Yes" << endl;
  return 0;
}
