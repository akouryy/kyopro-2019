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
  int N; cin >> N;
  vec<pair<int,int>> zp(N);
  times(N, i) {int A, B;cin >> A >> B; zp[i] = {B,A};}
  sort(begin(zp), end(zp));
  int k = 0;
  times(N, i) {
    k += zp[i].second; // A
    if(k > zp[i].first) {// B
      cout << "No" ln;
      goto next_case;
    }
  }
  cout << "Yes" ln;
  next_case:;
}

signed main() {
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(10);
  solve();
return 0;
}
