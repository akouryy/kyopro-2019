#include "base.hpp"
#include "graph.hpp"
#include "flow.hpp"

void solve() {
// NGEG(P)E(AB)
/* <foxy.memo-area> */
int N;int G;int E;cin>>N;cin>>G;cin>>E;VI P(G);times(G,Ri_0){cin>>P[Ri_0];}VI A(
E);VI B(E);times(E,Ri_0){cin>>A[Ri_0];cin>>B[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit, int> g(N + 1);
  times(G, i) g.add_dedge(P[i], N, 1);
  times(E, i) g.add_uedge(A[i], B[i], 1);

  dinic<int, unit, int> d(g);
  cout << d.exec(0, N) ln;
}
