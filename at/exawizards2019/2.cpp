#include "base.hpp"
#include "consts.hpp"

void solve() {
// N"S"
/* <foxy.memo-area> */
int N;string S;cin>>N;cin>>S;
/* </foxy.memo-area> */

  int r = 0;
  times(N, i) r += S[i] == 'R';

  cout << (r > N - r ? dict::Yes : dict::No) ln;
}
