//#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve() {
  int T;cin>>T;times(T,gcj_case_id) {
    // A
    /* <foxy.memo-area> */
    int A;cin>>A;
    /* </foxy.memo-area> */

    int c = 0;
    WC z(3, VC(3));

    while(true) {
      cout << 4 sp << c * 3 + 4 << endl;

      // IJ
      /* <foxy.memo-area> */
      int I;int J;cin>>I;cin>>J;
      /* </foxy.memo-area> */

      if(I == 0 && J == 0) break;
      if(I < 0 && J < 0) exit(0);

      z[I % 3][J % 3] = true;

      bool all_ok = true;
      times(3, i) times(3, j) {
        all_ok = all_ok && z[i][j];
      }
      if(all_ok) {
        z = WC(3, VC(3));
        c += 1;
      }
    }
  }
}
