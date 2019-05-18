#include "base.hpp"
#include "snake.hpp"

void solve() {
// HWNN(A)
/* <foxy.memo-area> */
int H;int W;int N;cin>>H;cin>>W;cin>>N;VI A(N);times(N,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  WI ans(H, VI(W));

  int s = 0;
  times(N, i) times(A[i], o) {
    PII p = snake_zigzag_number_to_pos(H, W, s);
    ans[p.first][p.second] = i + 1;
    ++s;
  }

  cout << ans ln;
}
