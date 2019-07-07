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

void solve() {
  string s; cin >> s;
  if(s[0] == s[1] || s[1] == s[2] || s[2] == s[3])
  cout << "Bad" ln;
  else cout << "Good" ln;
}

signed main() {
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(10);
  solve();
return 0;
}
