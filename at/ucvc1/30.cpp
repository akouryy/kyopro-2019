#include "base.hpp"
//#include "consts.hpp"
#include "perm.hpp"

void solve() {
// NN(AB)
/* <foxy.memo-area> */
int N;cin>>N;VI A(N);VI B(N);times(N,Ri_0){cin>>A[Ri_0];cin>>B[Ri_0];}
/* </foxy.memo-area> */

  VPII v(N); times(N, i) v[i] = {min(A[i], B[i]), max(A[i], B[i])};
  sort(iter(v));
  VI w(N * 2); times(N, i) { w[i * 2] = v[i].first; w[i * 2 + 1] = v[i].second; }

  cout << mint(inversion_number(w)) * 2_m .pow(N - 2) ln;
}
