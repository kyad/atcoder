// https://www.youtube.com/live/3QmnKGV0scU?t=6060s

#include <iostream>
#include <vector>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

long long power(long long m, long long n, int mod) {
  long long a = m % mod;
  long long ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return ans;
}

/// Dump vector from start. dump(x, 1) for 1-indexed.
template<typename T> void dump(const vector<T> &x, int start = 0) {
  for (size_t i = start; i < x.size(); i++) {
    cout << x.at(i) << (i + 1 == x.size() ? '\n' : ' ');
  }
}

int main() {
  int N;
  long long K;
  cin>>N>>K;
  vector<int>A(N);
  rep(i,N) cin >>A[i],A[i]--;
  
  vector<int> us;
  vector<int> ans(N,-1);
  vector<bool> vis(N,false);
  auto f = [&](auto f,int u)->void{
    vis[u]=true;
    us.push_back(u);
    if(vis[A[u]]) return;
    f(f,A[u]);
  };
  rep(u,N){
    if(vis[u])continue;
    us.clear();
    f(f,u);
    int M=us.size();
    int K2=power(2LL,K,M);
    rep(j,M){
      int u = us[j];
      ans[u] = us[(j+K2)%M]+1;
    }
  }
  dump(ans);
  return 0;
}
