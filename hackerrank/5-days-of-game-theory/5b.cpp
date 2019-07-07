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

vvec<int> edges;

int dfs(int i, int p) {
  int a = 0;
  for(int j : edges[i]) if(j != p) {
    a ^= dfs(j, i) + 1;
  }
  return a;
}

void solve() {
  vec<int> mx(100001); mx[0] = 1;
  upto(1, 100000, a) {
    int q = sqrt(a);
    int b = 0;
    upto(1, q, i) b += mx[a - i * i];
    mx[a] = b;

    if(b >= 1e18) { cerr << a ln; break; }
  }

  int T; cin >> T;
  times(T, i) {
    int N; cin >> N;

    times(100000, a) if(N <= mx[a]) {
      cout << a ln;
      break;
    }
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
