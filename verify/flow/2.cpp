#include "base.hpp"
#include "graph.hpp"
#include "flow.hpp"

void solve() {
// NMDM(-U-VPQW)
/* <foxy.memo-area> */
int N;int M;int D;cin>>N;cin>>M;cin>>D;VI U(M);VI V(M);VI P(M);VI Q(M);VI W(M);
times(M,Ri_0){cin>>U[Ri_0];--U[Ri_0];cin>>V[Ri_0];--V[Ri_0];cin>>P[Ri_0];cin>>Q[
Ri_0];cin>>W[Ri_0];}
/* </foxy.memo-area> */

  VPII vs; vs.reserve(M * 2);
  times(M, i) {
    vs.PB({U[i], P[i]});
    vs.PB({V[i], Q[i] + D});
  }
  auto cp = rab::compressed(vs);

  Graph<unit, int> g(cp.size);
  times(M, i) {
    g.add_dedge(cp.zip[{U[i], P[i]}], cp.zip[{V[i], Q[i] + D}], W[i]);
  }

  times(cp.size - 1, i) {
    if(cp.unzip[i].first == cp.unzip[i + 1].first) {
      g.add_dedge(i, i + 1, 1ll << 50);
    }
  }

  if(debug) {
    for(auto &es : g.edges) {
      for(auto &e : es) {
        cout << "(" << e.from sp << e.to sp << e.weight << ")" tb;
      }
      cout ln;
    }
  }

  dinic<int, unit, int> d(g);
  cout << d.exec(0, cp.size - 1) ln;
}
