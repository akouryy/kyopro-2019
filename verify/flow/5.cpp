#include "base.hpp"
#include "graph.hpp"
#include "flow.hpp"
constexpr int INF = 401;

void solve() {
// HWH("S")
/* <foxy.memo-area> */
int H;int W;cin>>H;cin>>W;VS S(H);times(H,Ri_0){cin>>S[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit, int> g(H * W * 2 + 2);

  int s = H * W * 2, t = H * W * 2 + 1;

  #define inp(i, j) (((i) * W + (j)) * 2)
  #define outp(i, j) (((i) * W + (j)) * 2 + 1)

  times(H, i) times(W, j) {
    g.add_dedge(inp(i, j), outp(i, j), 1);

    if(S[i][j] == 'X') {
      g.add_dedge(s, outp(i, j), INF);

      if(i == 0 || i == H - 1 || j == 0 || j == W - 1) {
        cout << -1 ln;
        return;
      }
    }
  }

  times(H, i) {
    g.add_dedge(outp(i, 0), t, INF);
    g.add_dedge(outp(i, W-1), t, INF);

    times(W-1, j) {
      g.add_dedge(outp(i, j), inp(i, j + 1), INF);
      g.add_dedge(outp(i, j + 1), inp(i, j), INF);
    }
  }
  times(W, j) {
    g.add_dedge(outp(0, j), t, INF);
    g.add_dedge(outp(H-1, j), t, INF);

    times(H-1, i) {
      g.add_dedge(outp(i, j), inp(i + 1, j), INF);
      g.add_dedge(outp(i + 1, j), inp(i, j), INF);
    }
  }

  dinic<int, unit, int> d(g);
  cout << d.exec(s, t) ln;
}
