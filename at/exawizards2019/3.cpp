#include "base.hpp"
#include "consts.hpp"

void solve() {
// NQ"S" Q("T" "D")
/* <foxy.memo-area> */
int N;int Q;string S;cin>>N;cin>>Q;cin>>S;VS T(Q);VS D(Q);times(Q,Ri_0){cin>>T[
Ri_0];cin>>D[Ri_0];}
/* </foxy.memo-area> */

  int l = 0, r = N - 1;
  rtimes(Q, i) {
    if(D[i][0] == 'L') {
      if(l < N && S[l] == T[i][0]) ++l;
      if(r < N-1 && S[r+1] == T[i][0]) ++r;
    } else {
      if(r >= 0 && S[r] == T[i][0]) --r;
      if(l >= 1 && S[l-1] == T[i][0]) --l;
    }
  }

  cout << max(0ll, r - l + 1) ln;
}
