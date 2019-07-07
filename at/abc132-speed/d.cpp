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

int fact[2001], fact_inv[2001];

int mpow(int a, int x) {
  int ret = 1;
  while(x) {
    if(x & 1) ret = ret * a % mod;
    a = a * a % mod;
    x /= 2;
  }
  return ret;
}

int nck(int n, int k) {
  if(n < k || k < 0) return 0;
  // cerr << "n " << fact[n] sp << fact_inv[k] sp << fact_inv[n - k] ln;
  return fact[n] * fact_inv[k] % mod * fact_inv[n - k] % mod;
}

void solve() {
  fact[0] = 1;
  times(2000, i) fact[i + 1] = fact[i] * (i + 1) % mod;

  // cerr << fact[2000] ln;

  fact_inv[2000] = mpow(fact[2000], mod - 2);
  rtimes(2000, i) fact_inv[i] = fact_inv[i + 1] * (i + 1) % mod;
  cerr << fact_inv[0] ln;

  int N, K; cin >> N >> K;
  upto(1, K, i) {
    if(N - K == 0) {
      cout << (i == 1 ? 1 : 0) ln;
    } else {
      cerr << nck(K - 1, i - 1) sp
        << nck(N - K - 1, i - 2) sp << nck(N - K - 1, i - 1) sp << nck(N - K - 1, i) ln;
      cout << nck(K - 1, i - 1) *
        ((nck(N - K - 1, i - 2) + nck(N - K - 1, i - 1) * 2 + nck(N - K - 1, i)) % mod) % mod ln;
    }
  }
}

signed main() {
  // cin.tie(0);
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(10);
  solve();
  return 0;
}
