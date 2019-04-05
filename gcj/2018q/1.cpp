#define GCJ_CASE
#include "base.hpp"
#include "consts.hpp"

int calc(VC& p) {
  int a = 0, b = 1;
  for(char c : p)
    if(c == 'C') b *= 2;
    else a += b;
  return a;
}

void solve(int gcj_case_id) {
// D "P"
/* <foxy.memo-area> */
int D;string P;cin>>D;cin>>P;
/* </foxy.memo-area> */

  VC p(iter(P));

  times(10000, i) {
    int k = calc(p);
    if(k <= D) {
      cout << i ln;
      return;
    }
    int j = p.size();
    while(j > 0 && p[j - 1] == 'C') --j;
    while(j > 0 && p[j - 1] == 'S') --j;
    if(j == 0) break;
    swap(p[j - 1], p[j]);
    // dd p;
  }

  cout << dict::IMPOSSIBLE ln;
}
