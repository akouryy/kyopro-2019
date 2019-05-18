#define GCJ_CASE
#include "base.hpp"
#include "graph.hpp"
//#include "consts.hpp"

void zp(Graph<unit, unit>& g, const VI &R, const VI &S, const VI &G, VB &par, VB &st, int i,
VB& visited) {
  if(visited[i]) return;
  if(par[i]) {
    st[i] = true;
    return;
  }
  par[i] = true;
  for(const auto &e : g.edges[i]) {
    zp(g, R, S, G, par, st, e.to, visited);
  }
  par[i] = false;
  visited[i] = true;
}

/* 0: none, 1: positive, 2: positive loop */
int zr(Graph<unit, unit>& g, const VI &R, const VI &S, const VI &G, VB &par,
       const VB &st, VI &memo, int i) {
  if(par[i]) return 0;
  if(memo[i] >= 0) return memo[i];
  par[i] = true;
  int tm = G[i] != 0;
  for(const auto &e : g.edges[i]) {
    amax(tm, zr(g, R, S, G, par, st, memo, e.to));
  }
  par[i] = false;
  if(tm == 2) return memo[i] = 2;
  if(tm == 1) return memo[i] = st[i] ? 2 : 1;
  return memo[i] = 0;
}

mint zq(Graph<unit, unit>& g, const VI &R, const VI &S, const VI &G, VB &par,
    VM &memo, VB &visited, int i) {
  if(par[i]) return 0_m;
  if(visited[i]) return memo[i];
  par[i] = true;
  memo[i] = mint(G[i]);
  for(const auto &e : g.edges[i]) {
    memo[i] += zq(g, R, S, G, par, memo, visited, e.to);
  }
  par[i] = false;
  visited[i] = true;
  return memo[i];
}

void solve(int gcj_case_id) {
// MM(-R-S)M(G)
/* <foxy.memo-area> */
int M;cin>>M;VI R(M + 1);VI S(M + 1);times(M,Ri_0){cin>>R[Ri_0];--R[Ri_0];cin>>S[Ri_0];
--S[Ri_0];}VI G(M + 1);times(M,Ri_0){cin>>G[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit, unit> g(M + 1);
  R[M] = S[M] = M;

  // if(R[0]) g.add_dedge(R[0], 0, unit());
  // if(S[0]) g.add_dedge(S[0], 0, unit());
  // if(!R[0] && !S[0]) {
  //   g.add_dedge(0, 0, unit());
  //   g.add_dedge(0, 0, unit());
  // }

  uptil(0, M, i) {
    g.add_dedge(R[i], i, unit());
    g.add_dedge(S[i], i, unit());
  }

  VB par(M), st(M), visited(M), visitedp(M);
  VI memor(M, -1);
  VM memoq(M);

  zp(g, R, S, G, par, st, 0, visitedp);
  if(R[0] || S[0]) st[0] = false;
  {if(debug)cerr<<"st: "<<(st)ln;}
  if(zr(g, R, S, G, par, st, memor, 0) == 2) {
    cout << "UNBOUNDED" ln;
    return;
  }
  {if(debug)cerr<<"memor: "<<(memor)ln;}
  cout << zq(g, R, S, G, par, memoq, visited, 0) ln;
}
