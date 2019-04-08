#include "base.hpp"
#include "graph.hpp"
#include "kruskal.hpp"

void solve() {
// NMKN(-C)M(-A-BW)
/* <foxy.memo-area> */
int N;int M;int K;cin>>N;cin>>M;cin>>K;VI C(N);times(N,Ri_0){cin>>C[Ri_0];--C[
Ri_0];}VI A(M);VI B(M);VI W(M);times(M,Ri_0){cin>>A[Ri_0];--A[Ri_0];cin>>B[Ri_0]
;--B[Ri_0];cin>>W[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit, int> g(N);
  times(M, j) g.add_uedge(A[j], B[j], W[j]);

  case12: {
    times(N, i) if(C[i] == -1) goto case3;
    HII cnt; times(N, i) ++cnt[C[i]];
    times(K, c) if(cnt[c] == 0) {
      cout << -1 ln; return;
    }

    VPII x(N); times(N, i) x[i] = { C[i], i };
    sort(iter(x));
    times(N - 1, k) if(x[k].first == x[k + 1].first) {
      g.add_uedge(x[k].second, x[k + 1].second, 0);
    }

    auto kr = rab::kruskal(g);
    if(!kr.is_connected()) {
      cout << -1 ln;
      return;
    }
    int ans2 = 0;
    times(N, i) for(auto& e : kr.edges[i]) {
      ans2 += e.weight; // weight * 2
    }
    cout << ans2 / 2 ln;
  }
  return;

  case3: {
    times(N, i) if(C[i] != -1) goto case4;

    auto kr = rab::kruskal(g, K - 1);
    if(kr.nue() != K - 1) {
      cout << -1 ln;
      return;
    }

    int ans2 = 0;
    times(N, i) for(auto& e : kr.edges[i]) {
      ans2 += e.weight; // weight * 2
    }
    cout << ans2 / 2 ln;
  }
  return;

  case4:;
}
