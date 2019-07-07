#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define uptil(a, b, i) for(int i = (a), b_ = (b); i < b_; ++i)
#define upto(a, b, i) for(int i = (a), b_ = (b); i <= b_; ++i)
#define downtil(a, b, i) for(int i = (a), b_ = (b); i > b_; --i)
#define downto(a, b, i) for(int i = (a), b_ = (b); i >= b_; --i)
#define times(n, i) uptil(0, n, i)
#define rtimes(n, i) downto((n)-1, 0, i)

#define sp <<" "
#define ln <<"\n"
#define size(v) ((int)(v).size())
template<class T> using vec=vector<T>;
template<class T> using vvec=vec<vector<T>>;

constexpr int mod = 1e9 + 7;

void solve() {
  int N, K; cin >> N >> K;

  int s = (int)sqrt(N);
  vec<int> dp(2 * s), dq(2 * s), sz(2 * s);

  times(s, i) sz[i] = 1;
  sz[s] = N / s - s;
  times(s-1, i) sz[2 * s - 1 - i] = N / (i + 1) - N / (i + 2);

  dp = sz;

  times(K - 1, h) {
    swap(dp, dq);
    fill(begin(dp), end(dp), 0);
    times(2 * s - 1, i) (dq[i + 1] += dq[i]) %= mod;
    times(2 * s, i) dp[i] = dq[2 * s - 1 - i] * sz[i] % mod;
    // times(2 * s, i) cerr << dp[i] << "\t" << dq[i] ln;
    // cerr ln;
  }


  int ans = 0;
  times(2 * s, i) ans = (ans + dp[i]) % mod;

  cout << ans ln;
}

signed main() {
  // cin.tie(0);
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(10);
  solve();
  return 0;
}
