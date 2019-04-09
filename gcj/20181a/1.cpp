#define GCJ_CASE
#include "base.hpp"
#include "consts.hpp"

void solve(int gcj_case_id) {
// RCHVR("X")
/* <foxy.memo-area> */
int R;int C;int H;int V;cin>>R;cin>>C;cin>>H;cin>>V;VS X(R);times(R,Ri_0){cin>>X
[Ri_0];}
/* </foxy.memo-area> */

  ++H; ++V;

  int n_choco = 0; times(R, i) times(C, j) n_choco += X[i][j] == '@';

  if(n_choco % H != 0 || n_choco / H % V != 0) {
    cout << dict::IMPOSSIBLE ln;
    dd n_choco; H; V;
    return;
  }
  if(n_choco == 0) {
    cout << dict::POSSIBLE ln;
    return;
  }

  int np = n_choco / H / V;

  VI cuth(1, 0); cuth.reserve(H + 1);
  {
    // cut H-1

    int now_c = 0;
    times(R, i) {
      times(C, j) now_c += X[i][j] == '@';
      if(now_c == np * V) {
        cuth.push_back(i + 1);
        now_c = 0;
      } else if(now_c > np * V) {
        cout << dict::IMPOSSIBLE ln;
        dd i; now_c; np * V;
        return;
      }
    }

    if(size(cuth) != H + 1) {
      cout << dict::IMPOSSIBLE ln;
      dd cuth; size(cuth); H;
      return;
    }
    // cuth.push_back(R);
  }

  VI cutv(1, 0); cutv.reserve(V + 1);
  {
    int now_c = 0;
    times(C, j) {
      times(R, i) now_c += X[i][j] == '@';
      if(now_c == np * H) {
        cutv.push_back(j + 1);
        now_c = 0;
      } else if(now_c > np * H) {
        cout << dict::IMPOSSIBLE ln;
        dd j; now_c; np * H;
        return;
      }
    }

    if(size(cutv) != V + 1) {
      cout << dict::IMPOSSIBLE ln;
      dd cutv; size(cutv); V;
      return;
    }
    // cutv.push_back(C);
  }

  times(H, k) times(V, l) {
    int now_c = 0;
    uptil(cuth[k], cuth[k + 1], i) uptil(cutv[l], cutv[l + 1], j) now_c += X[i][j] == '@';
    if(now_c != np) {
      cout << dict::IMPOSSIBLE ln;
      dd k; cuth; l; cutv; now_c; np;
      return;
    }
  }

  cout << dict::POSSIBLE ln;
}
