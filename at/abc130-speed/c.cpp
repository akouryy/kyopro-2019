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

void solve() {
  int W,H,X,Y; cin >>W>>H>>X>>Y;
  cout << (W * H / 2.0) sp << (X*2 == W && Y*2 == H ? 1 : 0) ln;
  next_case:;
}

signed main() {
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(6);
  solve();
  return 0;
}
