#include "base.hpp"
#include "graph_nibu.hpp"
#include "flow.hpp"

void solve() {
// ABMM(XY)
/* <foxy.memo-area> */
int A;int B;int M;cin>>A;cin>>B;cin>>M;VI X(M);VI Y(M);times(M,Ri_0){cin>>X[Ri_0
];cin>>Y[Ri_0];}
/* </foxy.memo-area> */

  VB colors(A + B); uptil(A, A + B, i) colors[i] = true;

  NibuGraph<unit, int> g(A + B, colors);
  times(M, i) g.add_uedge(X[i], A + Y[i], 1);

  dinic<int, unit, int> d(g.matcher(1));

  cout << d.exec(A + B, A + B + 1) ln;
}
