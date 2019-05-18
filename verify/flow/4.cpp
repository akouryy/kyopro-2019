#include "base.hpp"
#include "graph.hpp"
#include "flow.hpp"
constexpr int INF = 1ll << 50;

void solve() {
// HWH("A")
/* <foxy.memo-area> */
int H;int W;cin>>H;cin>>W;VS A(H);times(H,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit, int> g(H + W + 2);

  int s = H + W, t = H + W + 1;

  times(H, i) times(W, j) {
    if(A[i][j] == 'S') {
      g.add_dedge(s, i, INF);
      g.add_dedge(s, H + j, INF);
    } else if(A[i][j] == 'T') {
      g.add_dedge(i, t, INF);
      g.add_dedge(H + j, t, INF);
    } else if(A[i][j] == 'o') {
      g.add_uedge(i, H + j, 1);
    }
  }

  dinic<int, unit, int> d(g);
  int f = d.exec(s, t);
  if(f >= INF)
    cout << -1 ln;
  else
    cout << f ln;
}
