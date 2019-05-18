#include "base.hpp"
#include "snake.hpp"

void solve() {
// HWH("S")
/* <foxy.memo-area> */
int H;int W;cin>>H;cin>>W;VS S(H);times(H,Ri_0){cin>>S[Ri_0];}
/* </foxy.memo-area> */

  int hh = H / 2 + 1, ww = W / 2 + 1;

  int i0, j0;
  times(hh, i) times(ww, j) if(S[i * 2][j * 2] == '@') {
    i0 = i;
    j0 = j;
  }

  int s_last = 0;
  times(hh, i) times(ww, j) if(S[i * 2][j * 2] == '*') {
    amax(s_last, snake_spath_pos_to_number(hh, ww, i0, j0, i, j));
  }

  int oi = i0, oj = j0;

  upto(1, s_last, s) {
    int i, j;
    snake_spath_number_to_pos(hh, ww, i0, j0, s, i, j);
    S[i + oi][j + oj] = '#';
    if(S[i * 2][j * 2] == '.') {
      S[i * 2][j * 2] = '#';
    }
    oi = i; oj = j;
  }

  times(H, i) cout << S[i] ln;
}
