#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"
#include "graph_nibu.hpp"
#include "flow.hpp"

void solve(int gcj_case_id) {
// NN(N(A))
/* <foxy.memo-area> */
int N;cin>>N;WI A(N,VI(N));times(N,Ri_0){times(N,Ri_1){cin>>A[Ri_0][Ri_1];}}
/* </foxy.memo-area> */

  int match = 0;

  times(N * 2, c) {
    int nv = N * 2; // 行 or 列
    #define row(i) (i)
    #define col(j) (N + j)

    VB colors(nv);
    times(N, j) colors[col(j)] = true;

    NibuGraph<unit, int> nibu(nv, colors);
    times(N, i) times(N, j) {
      if(
        (c < N && A[i][j] > 0 && c == A[i][j] - 1) ||
        (c >= N && A[i][j] < 0 && c - N == -A[i][j] - 1)
      ) {
        nibu.add_uedge(row(i), col(j), 1);
      }
    }

    dinic<int, unit, int> d(nibu.matcher(1));
    int f = d.exec(nv, nv + 1);
    dd nibu.g.nue(); f;
    match += f;
  }

  cout << N * N - match ln;
}
