
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
#define upto(a,b,i) for(int i=(a),b_=(b);i<=b_;++i)
#define uptil(a,b,i) for(int i=(a),b_=(b);i<b_;++i)
#define downto(a,b,i) for(int i=(a),b_=(b);i>=b_;--i)
#define downtil(a,b,i) for(int i=(a),b_=(b);i>b_;--i)
#define times(n,i) uptil(0,n,i)
#define rtimes(n,i) downto((n)-1,0,i)
#define size(v) ((int)(v).size())
#define sp << " "
#define ln << endl
template<class T> using vec = vector<T>;

struct uf{
  int n;
  vec<int> par,rank;
  uf(int n):n(n),par(n,-1),rank(n,0){}

  int root(int i) {
    if(par[i]==-1) return i;
    return par[i] = root(par[i]);
  }
  bool merge(int a,int b) {
    a=root(a);
    b=root(b);
    if(a==b) return 0;
    if(rank[a] > rank[b]) swap(a,b);
    par[a] = b;
    ++rank[b];
    return 1;
  }
};

void solve() {
  int N; cin >> N;

  vec<int> xs(N), ys(N);
  vec<pair<int,int>> xis(N), yis(N);
  times(N,i) {
    cin >> xs[i] >> ys[i];
    xis[i] = {xs[i], i};
    yis[i] = {ys[i], i};
  }
  sort(begin(xis), end(xis));
  sort(begin(yis), end(yis));
  uf uf(N);
  times(N-1,i) {
    if(xis[i].first == xis[i+1].first) {
      uf.merge(xis[i].second, xis[i+1].second);
    }
    if(yis[i].first == yis[i+1].first) {
      uf.merge(yis[i].second, yis[i+1].second);
    }
  }

  map<int, set<int>> xset;
  map<int, set<int>> yset;

  times(N,i) {
    xset[uf.root(i)].insert(xs[i]);
    yset[uf.root(i)].insert(ys[i]);
  }

  int ans = -N;
  for(auto &p : xset) {
    ans += size(p.second) * size(yset[p.first]);
  }

  cout << ans ln;

  next_case:;
}

signed main() {
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(10);
  solve();
return 0;
}
