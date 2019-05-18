#include "base.hpp"
constexpr LD EPS = 1e-10;
#include "geo_totuxau.hpp"
//#include "consts.hpp"

void solve() {
  while(1) {
    int N; cin >> N;
    if(!N) return;
    vec<GVec<LD>> XY(N); char comma;
    times(N, i) cin >> XY[i].x >> comma >> XY[i].y;

    cout << N - size(convex_hull(XY)) ln;
  }
}
