#include "base.hpp"
#include "graph_scc.hpp"

void solve() {
// NMM(ST)QQ(UV)
/* <foxy.memo-area> */
int N;int M;int Q;cin>>N;cin>>M;VI S(M);VI T(M);times(M,Ri_0){cin>>S[Ri_0];
cin>>T[Ri_0];}cin>>Q;VI U(Q);VI V(Q);times(Q,Ri_0){cin>>U[Ri_0];cin>>V[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit> g(N);
  times(M, i) g.add_dedge(S[i], T[i], {});

  SCC<unit> scc(g); scc.exec();

  times(Q, i) {
    cout << (scc.zip[U[i]] == scc.zip[V[i]] ? 1 : 0) ln;
  }
}
