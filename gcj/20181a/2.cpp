#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int gcj_case_id) {
// RBCC(MSP)
/* <foxy.memo-area> */
int R;int B;int C;cin>>R;cin>>B;cin>>C;VI M(C);VI S(C);VI P(C);times(C,Ri_0){
cin>>M[Ri_0];cin>>S[Ri_0];cin>>P[Ri_0];}
/* </foxy.memo-area> */

  int ng = 0, ok = LLONG_MAX;
  while(abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    VI bs(C);
    times(C, i) {
      bs[i] = clamp((mid - P[i]) / S[i], 0ll, M[i]);
    }
    sort(iter(bs));
    dd bs;
    int sum = 0;
    uptil(C - R, C, i) sum += bs[i];
    dd mid; sum;
    if(sum >= B) ok = mid;
    else ng = mid;
  }

  cout << ok ln;
}
