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
  int T; cin >> T;

  times(T, i) {
    int N; cin >> N;
    edges.clear(); edges.resize(N);
    times(N-1, i) {
      int U, V; cin >> U >> V; --U; --V;
      edges[U].push_back(V);
      edges[V].push_back(U);
    }

    cout << (dfs(0, 0) ? "Alice" : "Bob") ln;
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
