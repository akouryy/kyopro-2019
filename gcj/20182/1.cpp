#define GCJ_CASE
#include "base.hpp"
#include "consts.hpp"

void solve(int gcj_case_id) {
// CC(B)
/* <foxy.memo-area> */
int C;cin>>C;VI B(C);times(C,Ri_0){cin>>B[Ri_0];}
/* </foxy.memo-area> */

  if(B[0] == 0 || B[C-1] == 0) {
    cout << dict::IMPOSSIBLE ln;
    return;
  }

  VS ans(C, string(C, '.')); // ans.reserve(C * C);

  int bi = 0;
  upto(0, C - 2, i) {
    if(bi > i) {
      uptil(i, bi, j) {
        ans[C - (bi - j)][j] = '\\';
      }
    } else if(bi == i) {
      // nop
    } else {
      downtil(i, bi, j) {
        ans[C - (j - bi)][j] = '/';
      }
    }
    --B[bi];
    dd i; bi;
    while(bi < C && B[bi] == 0) ++bi;
  }

  int r = 0;
  while(r < size(ans)) {
    for(char c : ans[r]) if(c != '.') {
      goto output;
    }
    ++r;
  }
  output:;
  cout << size(ans) + 1 - r ln;
  uptil(r, size(ans), i) cout << ans[i] ln;
  cout << string(C, '.') ln;
}
