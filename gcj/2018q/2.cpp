#define GCJ_CASE
#include "base.hpp"
#include "consts.hpp"

void solve(int gcj_case_id) {
// NN(V)
/* <foxy.memo-area> */
int N;cin>>N;VI V(N);times(N,Ri_0){cin>>V[Ri_0];}
/* </foxy.memo-area> */

  WI a(2);
  times(N, i) a[i % 2].push_back(V[i]);
  sort(iter(a[0]));
  sort(iter(a[1]));

  times(N-1, i) {
    if(a[i % 2][i / 2] > a[(i + 1) % 2][(i + 1) / 2]) {
      cout << i ln;
      return;
    }
  }

  cout << dict::OK ln ln;
}
