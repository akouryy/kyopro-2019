#include "base.hpp"
constexpr LD EPS = 1e-10;
#include "geo_totuxau.hpp"
//#include "consts.hpp"

void solve() {
  int N; cin >> N;
  if(!N) return;
  vec<GVec<LD>> A(N); times(N, i) cin >> A[i].x >> A[i].y;
  vec<GVec<LD>> B(N); times(N, i) cin >> B[i].x >> B[i].y;

  auto ac = convex_hull(A), bc = convex_hull(B);

  dd ac; bc;

  auto af = farthest_points(ac), bf = farthest_points(bc);

  cout << sqrt(bc[bf.first].dist2(bc[bf.second])) / sqrt(ac[af.first].dist2(ac[af.second])) ln;
}
