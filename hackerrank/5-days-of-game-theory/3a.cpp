#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define int LL
#define upto(a, b, i) for(int i = (a), b_ = (b); i <= b_; ++i)
#define uptil(a, b, i) for(int i = (a), b_ = (b); i < b_; ++i)
#define downto(a, b, i) for(int i = (a), b_ = (b); i >= b_; --i)
#define downtil(a, b, i) for(int i = (a), b_ = (b); i > b_; --i)
#define times(n, i) uptil(0, n, i)
#define rtimes(n, i) downto((n) - 1, 0, i)
#define sp << " "
#define ln << "\n"
#define size(v) ((int)(v).size())
template<class T> using vec = vector<T>;
template<class T> using vvec = vec<vec<T>>;

map<int, int> prime_factor(int n) {
  map<int, int> m;
  upto(2, sqrt(n), i) {
    while(n % i == 0) ++m[i], n /= i;
  }
  if(n != 1) ++m[n];
  return m;
}

void solve() {
  int T; cin >> T;
  times(T, i) {
    int N; cin >> N;
    int xg = 0;
    times(N, i) {
      int H; cin >> H;
      auto pf = prime_factor(H);
      int k = H % 2 == 0;
      for(auto p : pf) if(p.first != 2) k += p.second;
      xg ^= k;
    }
    cout << (xg ? 1 : 2) ln;
  }
}

signed main(){
  cin.tie(0);
  cerr.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(6);
  solve();
  return 0;
}
