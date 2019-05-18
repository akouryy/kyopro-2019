#include "base.hpp"
#include "snake.hpp"
//#include "consts.hpp"

void solve() {
// T
/* <foxy.memo-area> */
int T;cin>>T;
/* </foxy.memo-area> */

  times(T, t) {

// NMXY
/* <foxy.memo-area> */
int N;int M;int X;int Y;cin>>N;cin>>M;cin>>X;cin>>Y;
/* </foxy.memo-area> */
--X; --Y;

    if(N % 2 != 0 && M % 2 != 0 && X % 2 != Y % 2) {
      cout << -1 ln; continue;
    }

    WI ans(N, VI(M));
    times(N, i) times(M, j) {
      ans[i][j] = 1 + snake_spath_pos_to_number(N, M, X, Y, i, j);
    }
    cout << ans ln;
  }
}
