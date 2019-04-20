#include "base.hpp"
#include "math.hpp"
#include "prime.hpp"

void solve() {
int N;cin>>N;VI A(N+1);rtimes(N+1,Ri_0){cin>>A[Ri_0];}

  int s = 0;
  times(N+1, i) {
    s = gcd(s, A[i]);
  }
  auto pfs = prime_factor(s);
  VI ans;
  for(auto& p : pf) ans.PB(p.first);

  auto pf = prime_factor(A[0]);
  for(auto& pair : pf) {
    int p = pair.first;

    if(p.)
  }

/*
  int k = 0;
  times(N+1, i) k += A[i] % 2;
  if(A[0] % 2 == 0 && k % 2 == 0) {
    cout << 2 ln;
  }

  int s = 0;
  times(N+1, i) {
    s = gcd(s, A[i]);
  }

  auto pf = prime_factor(s);
  VI ans;
  for(auto& p : pf) if(p.first > 2) ans.PB(p.first);
  sort(iter(ans));
  for(int a : ans) cout << a ln;
*/
}
