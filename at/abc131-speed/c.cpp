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

int gcd(int c, int d) {
  if(d == 0) return c;
  return gcd(d, c % d);
}

int lcm(int c, int d) {
  return c / gcd(c, d) * d;
}

void solve() {
  int A,B,C,D; cin >> A>>B>>C>>D;
  cerr <<
    (B - B / C - B / D + B / lcm(C, D)) sp <<
    (A-1 - (A-1) / C - (A-1) / D + (A-1) / lcm(C, D)) ln;
  cout <<
    (B - B / C - B / D + B / lcm(C, D)) -
    (A-1 - (A-1) / C - (A-1) / D + (A-1) / lcm(C, D)) ln;
}

signed main() {
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(10);
  solve();
return 0;
}
