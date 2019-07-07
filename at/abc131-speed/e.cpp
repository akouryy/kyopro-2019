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
#define sp << " "
#define ln << endl
template<class T> using vec = vector<T>;

void solve() {
  int N,K; cin >> N>>K;

  int mp = (N-1)*(N-2)/2 - K;

  if(mp < 0) {
    cout << -1 ln;
    goto next_case;
  }

  cout << (mp + (N-1)) ln;
  times(N-1, i) cout << (i)+1 sp << (N-1)+1 ln;

  times(N-1, i) times(i, j) {
    if(mp == 0) goto next_case;
    cout << (i)+1 sp << (j)+1 ln;
    --mp;
  }

  next_case:;
}

signed main() {
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(10);
  solve();
return 0;
}
