#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

int dfs(int i, VS::iterator l, VS::iterator r) {
  int cnt = 0;
  while(l != r && size(*l) <= i) {
    ++l;
    ++cnt;
  }

  auto l0 = l;

  while(l != r) {
    auto l1 = l;
    char c = (*l)[i];
    while(l != r && (*l)[i] == c) ++l;
    cnt += dfs(i + 1, l1, l);
    // int d = dfs(i + 1, l1, l);
    // if(d >= 2) cnt += d - 2;
    // else cnt += d;
  }

  dd i; l0 == r ? "null" : *l0; l0 == r ? "null" : *(r - 1); r - l0; cnt;

  if(cnt >= 2 && i >= 1) return cnt - 2;
  else return cnt;
  // return cnt;
}

void solve(int gcj_case_id) {
// NN("W")
/* <foxy.memo-area> */
int N;cin>>N;VS W(N);times(N,Ri_0){cin>>W[Ri_0];}
/* </foxy.memo-area> */

  times(N, i) reverse(iter(W[i]));

  sort(iter(W));

  int ans = N - dfs(0, iter(W));

  cout << ans ln;
}

/* <rab:gen/> */
