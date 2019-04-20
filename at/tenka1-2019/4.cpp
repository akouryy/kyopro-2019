#define MOD 998244353
#include "base.hpp"
#include "nck.hpp"
//#include "consts.hpp"

mint dp[6001][3001];

void solve() {
// N X
/* <foxy.memo-area> */
int N;int X;cin>>N;cin>>X;
/* </foxy.memo-area> */

  dp[0][0] = 1m;

  VM anss(N + 1);

  times(N, i) {
    times(X, j) {
      dp[j + 1][i + 1] += dp[j][i];

      if(j + 2 <= X) dp[j + 2][i + 1] += dp[j][i];
    }
  }

  // dd dp;

  // mint ans1 = 0_m, ans2 = 0_m;
  upto(0, N, i) {
    times(X, j) {
      anss[i] += dp[j][i];
    }
  }
  dd anss; '?';

  upto(1, min(N / 2, (X - 1) / 2), a) {
    // dd a;
    upto(0, N - 2 * a, k) {
      // dd k; X - 1 - 2 * a; (N - 2 * a) - k; dp[X - 1 - 2 * a][(N - 2 * a) - k];
      anss[N - k] += dp[X - 1 - 2 * a][(N - 2 * a) - k];
    }
  }

  dd anss; '*';

  if(X % 2 == 1 && N > (X - 1)) {
    upto(1, N - (X - 1), t) {
      anss[X - 1 + t] += 1_m; // 22...22
    }
  }

  dd anss; '!';
  mint ans = 0_m;
  fact_init(N);
  times(N + 1, k) ans += anss[k] * nCk(N, k);

  cout << ans ln;
}
