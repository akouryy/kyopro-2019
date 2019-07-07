#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
#define upto(a, b, i) for(int i = (a),b_ =(b); i <= b_; ++i)
#define uptil(a, b, i) for(int i = (a),b_ =(b); i < b_; ++i)
#define downto(a, b, i) for(int i = (a),b_ =(b); i >= b_; --i)
#define downtil(a, b, i) for(int i = (a),b_ =(b); i > b_; --i)
#define times(n, i) uptil(0, (n), i)
#define rtimes(n, i) downto((n) - 1,0, i)
#define size(a) ((int)(a).size())
#define ln << endl
#define sp << " "

template<class T> using vec = vector<T>;
template<class T> using vvec = vec<vec<T>>;

constexpr int mod = 1e9 + 7;

void solve() {
  int N,M; cin>>N>>M;
  vec<int> S(N), T(M);
  times(N, i) cin>>S[i];
  times(M, j) cin>>T[j];

  vvec<int> dp(N+1, vec<int>(M+1, 1));

  upto(1, N, i) upto(1, M, j) {
    dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] * (S[i-1] != T[j-1]) + mod) % mod;
  }
  cout << dp[N][M] ln;
}

signed main() {
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(6);
  solve();
  return 0;
}
