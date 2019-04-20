#include "base.hpp"

void solve() {
// N "S"
/* <foxy.memo-area> */
int N;string S;cin>>N;cin>>S;
/* </foxy.memo-area> */

  VI a(N + 1), b(N + 1);

  times(N, i) a[i + 1] = a[i] + (S[i] == '#');
  rtimes(N, i) b[i] = b[i + 1] + (S[i] == '.');
  dd a; b;

  int ans = LLONG_MAX;
  times(N + 1, i) amin(ans, a[i] + b[i]);

  cout << ans ln;
}
