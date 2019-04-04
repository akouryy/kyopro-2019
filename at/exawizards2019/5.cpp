#include "base.hpp"
#include "nck.hpp"

void solve() {
// BW
/* <foxy.memo-area> */
int B;int W;cin>>B;cin>>W;
/* </foxy.memo-area> */

  bool bad = B < W;
  if(bad) swap(B, W);

  mint half = 1_m / 2_m;

  times(W, i) cout << half ln;

  mint pyon = 1_m / 2_m .pow(W);
  uptil(W, B, i) {
    mint a = pyon + (1_m - pyon) / 2_m;
    cout << (bad ? 1_m - a : a) ln;

    pyon += nCk(i, W - 1) / 2_m .pow(i + 1);
  }

  mint qyon = 1_m / 2_m .pow(B);
  uptil(B, B + W, i) {
    mint a = pyon + (1_m - pyon - qyon) / 2_m;
    cout << (bad ? 1_m - a : a) ln;

    pyon += nCk(i, W - 1) / 2_m .pow(i + 1);
    qyon += nCk(i, B - 1) / 2_m .pow(i + 1);
  }
}
