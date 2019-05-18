#include "base.hpp"
#include "graph.hpp"
#include "flow.hpp"

void solve() {
// NMM(UVC)
/* <foxy.memo-area> */
int N;int M;cin>>N;cin>>M;VI U(M);VI V(M);VI C(M);times(M,Ri_0){cin>>U[Ri_0];
cin>>V[Ri_0];cin>>C[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit, int> g(N);
  times(M, i) {
    g.add_dedge(U[i], V[i], C[i]);
  }

  dinic<int, unit, int> d(g);
  cout << d.exec(0, N - 1) ln;
}
