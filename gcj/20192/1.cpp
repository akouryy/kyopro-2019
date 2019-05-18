#define GCJ_CASE
#include "base.hpp"
#include "math.hpp"
//#include "consts.hpp"

void solve(int gcj_case_id) {
// NN(CJ)
/* <foxy.memo-area> */
int N;cin>>N;VI C(N);VI J(N);times(N,Ri_0){cin>>C[Ri_0];cin>>J[Ri_0];}
/* </foxy.memo-area> */

  set<PII> ks;

  times(N, i) times(N, j) if(i != j) {
    if(C[i] > C[j] && J[i] < J[j]) {
      int a = J[j] - J[i], b = C[i] - C[j];
      int g = gcd(a, b);
      ks.insert({a / g, b / g});
    }
  }

  cout << size(ks) + 1 ln;
}
