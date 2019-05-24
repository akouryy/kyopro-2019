#define GCJ_CASE
#include "base.hpp"
#include "consts.hpp"
#include "math_rational_bsearch.hpp"

void solve(int gcj_case_id) {
// NN(CJ)
/* <foxy.memo-area> */
int N;cin>>N;VI C(N);VI J(N);times(N,Ri_0){cin>>C[Ri_0];cin>>J[Ri_0];}
/* </foxy.memo-area> */

  Rational p(1, 0), r(0, 1);

  times(N, a) uptil(a + 1, N, b) {
    // c * C[a] + j * J[a] < c * C[b] + j * J[b]
    if(C[b] > C[a]) {
      if(J[b] >= J[a]) continue; // always true
      Rational pp(C[b] - C[a], J[a] - J[b]);
      // c * pp > j * qq
      dd a; b; p; pp; p < pp; p == pp;
      amin(p, pp);
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
      Rational rr(C[a] - C[b], J[b] - J[a]);
      dd a; b; r; rr; r < rr; r == rr;
      // c * rr < j * ss
      amax(r, rr);
    }
  }
  dd p; r;
  if(p <= r) {
    cout << dict::IMPOSSIBLE ln;
    return;
  }

  Rational a = rational_bsearch_between_exclusive(r, p);

  cout << a.bo sp << a.si ln;
}
