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
  int N,K; cin>>N>>K;
  vec<int> A(N); times(N,i) cin>>A[i];

  int s=0,j=0,ans=0;
  times(N,i) {
    while(j < N && s < K) { s += A[j]; ++j; }
    if(j == N && s < K) ++j;
    ans += N + 1 - j;
    cerr << i sp << j ln;
    s -= A[i];
  }
  cout << ans ln;
}

signed main() {
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(6);
  solve();
  return 0;
}
