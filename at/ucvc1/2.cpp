#include "base.hpp"
#include "graph.hpp"
#include "uf.hpp"

namespace kpl {
  template<class V, class E>
  Graph<V, E> kruskal_with_sorted_edgeX(const Graph<V, E>& g, const vector<Edge<E>>& es, int x) {
    Graph<V, E> t(g.nv());
    unionfind uf(g.nv());

    for(const auto& e : es) {
      E cost; unsigned i, j; tie(cost, i, j) = e;
      if(uf.merge(i, j)) { /* true: 今まで違う木に属していた */
        t.add_uedge(i, j, cost);
        --x;
        if(x == 0) return t;
      }
    }

    uptil(1, g.nv(), i) if(!uf.is_same(0, i)) {
      throw -1ll;
    }

    return t;
  }

  template<class V, class E>
  Graph<V, E> kruskalX(const Graph<V, E>& g, int x) {
    // vec<Edge<E>> edges = kpl::flatten(g.edges, g.ne());
    vec<Edge<E>> ret;
    ret.reserve(g.ne());
    for(const auto& xs : g.edges) append(ret, xs);
    ret.shrink_to_fit();
    auto edges = ret;

    sort(iter(edges));
    return kruskal_with_sorted_edgeX(g, edges, x);
  }
}

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

    try {
      auto kr = kpl::kruskalX(g, N);
      int ans2 = 0;
      times(N, i) for(auto& e : kr.edges[i]) {
        ans2 += get<0>(e); // weight * 2
      }
      cout << ans2 / 2 ln;
    } catch(int not_connected) {
      cout << -1 ln;
    }
  }
  return;

  case3: {
    times(N, i) if(C[i] != -1) goto case4;
    try {
      auto kr = kpl::kruskalX(g, K - 1);
      int ans2 = 0;
      times(N, i) for(auto& e : kr.edges[i]) {
        ans2 += get<0>(e); // weight * 2
      }
      cout << ans2 / 2 ln;
    } catch(int not_connected) {
      cout << -1 ln;
    }
  }
  return;

  case4:;
}
