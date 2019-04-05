#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int gcj_case_id) {
// A.
/* <foxy.memo-area> */
LD A;cin>>A;
/* </foxy.memo-area> */

  if(A * A <= 2) {
    LD a = A / 2;
    LD b = sqrt(0.5 - a * a);
    cout << 0.0 sp << 0.0 sp << 0.5 ln;
    cout << (a - b) / 2 sp << (a + b) / 2 sp << 0.0 ln;
    cout << (-a - b) / 2 sp << (a - b) / 2 sp << 0.0 ln;
  } else {
    LD small = 0, big = sqrt(1.0l / 6);
    times(500, i) {
      LD mid = (small + big) / 2;
      LD area = 2 * sqrt(2 * (0.25 - mid * mid)) + 2 * mid;
      if(area < A) {
        small = mid;
      } else {
        big = mid;
      }
    }
    LD c = (small + big) / 2;
    // cout << 0.0 sp << 0.0 sp << 0.5 ln;
    cout << sqrt(0.25 - c * c) sp << c sp << 0.0 ln;
    LD s = -sqrt(2.0l) * c / 2, t = sqrt(2 * (0.25 - c * c)) / 2;
    cout << s sp << t sp << sqrt(0.25 - s * s - t * t) ln;
    cout << s sp << t sp << -sqrt(0.25 - s * s - t * t) ln;
  }
}
