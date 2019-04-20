#include "base.hpp"
//#include "consts.hpp"

void solve() {
// NN(A)
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);times(N,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  VI s(90001); s[0] = 1;
  times(N, i) rtimes(90001, j) {
    if(j >= A[i]) s[j] += s[j - A[i]];
  }

  cout << ans ln;
}
