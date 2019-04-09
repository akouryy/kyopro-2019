#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int gcj_case_id) {
// NPN(WH)
/* <foxy.memo-area> */
int N;int P;cin>>N;cin>>P;VI W(N);VI H(N);times(N,Ri_0){cin>>W[Ri_0];cin>>H[Ri_0
];}
/* </foxy.memo-area> */

  int diff = 0;
  times(N, i) diff += 2 * (W[i] + H[i]);
  P -= diff;

  VD dp(250 * 2 * 100 + 1, -1); dp[0] = 0;

  times(N, i) {
    int lo = min(W[i], H[i]) * 2;
    LD hi = sqrt(W[i] * W[i] + H[i] * H[i]) * 2;

    rtimes(size(dp) - lo, i) if(dp[i] >= 0) {
      amax(dp[i + lo], dp[i] + hi - lo);
    }
  }

  LD ans = 0;

  times(size(dp), i) if(dp[i] >= 0 && i <= P) {
    amax(ans, clamp(i + dp[i], 0.0l, (LD)P));
  }

  cout << ans + diff ln;
}
