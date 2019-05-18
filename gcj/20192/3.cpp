#define GCJ_CASE
#include "base.hpp"
#include "consts.hpp"

PII sternBrocot(int p, int q, int r, int s) {
  int xl = 0, yl = 1, xr = 1, yr = 0;

  while(true) {
    int xm = xl + xr, ym = yl + yr;

    if(r * ym < xm * s) {
      if(xm * q < p * ym) {
        return {xm, ym};
      } else {
        xr = xm; yr = ym;
      }
    } else {
      xl = xm; yl = ym;
    }
  }
}

void solve(int gcj_case_id) {
// NN(CJ)
/* <foxy.memo-area> */
int N;cin>>N;VI C(N);VI J(N);times(N,Ri_0){cin>>C[Ri_0];cin>>J[Ri_0];}
/* </foxy.memo-area> */

  int p = 1, q = 0, r = 0, s = 1;

  times(N, a) uptil(a + 1, N, b) {
    // c * C[a] + j * J[a] < c * C[b] + j * J[b]
    if(C[b] > C[a]) {
      if(J[b] >= J[a]) continue; // always true
      int pp = C[b] - C[a], qq = J[a] - J[b];
      // c * pp > j * qq
      if(p * qq > pp * q) { p = pp; q = qq; }
    } else if(C[b] == C[a]) {
      if(J[b] > J[a]) continue; // always true
      // always false
      cout << dict::IMPOSSIBLE ln;
      return;
    } else {
      if(J[b] <= J[a]) { // always false
        cout << dict::IMPOSSIBLE ln;
        return;
      }
      int rr = C[a] - C[b], ss = J[b] - J[a];
      // c * rr < j * ss
      if(r * ss < rr * s) { r = rr; s = ss; }
    }
  }
  dd p; q; r; s;
  if(p * s <= r * q) {
    cout << dict::IMPOSSIBLE ln;
    return;
  }

  PII a = sternBrocot(p, q, r, s);

  cout << a.second sp << a.first ln;
}
