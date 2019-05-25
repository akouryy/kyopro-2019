#define GCJ_CASE
#include "base.hpp"
#include "graph.hpp"
#include "graph_scc.hpp"
//#include "consts.hpp"

void dfs(const Graph<unit> &scc, const VM &zw, VM &tw,
  const VB &znz, VB &tnz,
  VB &visited, int i
) {
  if(visited[i]) return;
  visited[i] = true;
  for(auto &e : scc.edges[i]) {
    dfs(scc, zw, tw, znz, tnz, visited, e.to);
    tw[i] += tw[e.to] + zw[e.to];
    tnz[i] = tnz[i] || tnz[e.to] || znz[e.to];
  }
}

bool isUnbound(
  const SCCer<unit> &sccer,
  const Graph<unit> &scc, const Graph<unit> &g,
  const VM &zw, const VM &tw,
  const VB &znz, const VB &tnz,
  VB &visited, VB &unbounded, int i,
  bool init
) {
  if(visited[i]) return unbounded[i];
  if(size(sccer.unzip[i]) >= 2 && (znz[i] || tnz[i])) {
    if(!init) return unbounded[i] = true;
    for(int gi : sccer.unzip[i]) {
      int c = 0;
      for(auto &ge : g.edges[gi]) {
        c += sccer.zip[ge.to] == i;
      }
      if(c >= 2) return unbounded[i] = true;
    }
  }

  for(auto &e : scc.edges[i]) {
    if(isUnbound(sccer, scc, g, zw, tw, znz, tnz, visited, unbounded, e.to, false))
      return unbounded[i] = true;
  }
  return unbounded[i] = false;
}

void solve(int gcj_case_id) {
// MM(-R-S)M(G)
/* <foxy.memo-area> */
int M;cin>>M;VI R(M + 1);VI S(M + 1);times(M,Ri_0){cin>>R[Ri_0];--R[Ri_0];cin>>S[Ri_0];
--S[Ri_0];}VI G(M + 1);times(M,Ri_0){cin>>G[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit> g(M);

  times(M, i) {
    g.add_dedge(R[i], i, {});
    g.add_dedge(S[i], i, {});
  }

  SCCer<unit> sccer(g); sccer.exec();
  const Graph<unit> &scc = sccer.scc;

  int z = scc.nv(), z0 = sccer.zip[0];
  VM zw(z);
  VB nonzero(z), inf_inner(z), inf_outer(z);

  times(M, i) {
    zw[sccer.zip[i]] += (mint)G[i];
    nonzero[sccer.zip[i]] = nonzero[sccer.zip[i]] || G[i] > 0;
  }

  rtimes(z, i) {
    for(auto &e : scc.edges[i]) {
      zw[i] += zw[e.to];
      nonzero[i] = nonzero[i] || nonzero[e.to];
    }
    if(nonzero[i]) {
      if(size(sccer.unzip[i]) >= 2) {
        inf_outer[i] = true;
        for(int gi : sccer.unzip[i]) {
          int c = 0;
          for(auto &ge : g.edges[gi]) {
            c += sccer.zip[ge.to] == i;
          }
          if(c >= 2) {
            inf_inner[i] = true;
            break;
          }
        }
      } else {
        int gi = sccer.unzip[i][0];
        for(auto &ge : g.edges[gi]) {
          if(ge.to == gi) inf_outer[i] = true;
        }
      }
    }
    for(auto &e : scc.edges[i]) {
      inf_outer[i] = inf_outer[i] || inf_outer[e.to];
      inf_inner[i] = inf_inner[i] || inf_outer[e.to];
    }
  }

  if(inf_inner[sccer.zip[0]])
    cout << "UNBOUNDED" ln;
  else
    cout << zw[z0] ln;
}
