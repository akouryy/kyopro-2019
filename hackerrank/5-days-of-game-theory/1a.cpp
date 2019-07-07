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

void solve() {
  vec<int> gr(101);
  upto(1, 100, i) {
    int g = 0;
    while(
      i >= 2 && gr[i - 2] == g ||
      i >= 3 && gr[i - 3] == g ||
      i >= 5 && gr[i - 5] == g
    ) ++g;
    gr[i] = g;
  }

  int T; cin >> T;
  times(T, i) {
    int N; cin >> N;
    cout << (gr[N] ? "First" : "Second") ln;
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
