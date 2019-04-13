#define GCJ_CASE
#include "base.hpp"
#include "consts.hpp"

bool swapped; // init for each test case!!!

inline void out(int i, int j) {
  if(swapped) swap(i, j);
  cout << i + 1 sp << j + 1 ln;
}

void solve(int gcj_case_id) {
// RC
/* <foxy.memo-area> */
int R;int C;cin>>R;cin>>C;
/* </foxy.memo-area> */

  if(R > C) {
    swapped = true;
    swap(R, C);
  } else {
    swapped = false;
  }
  if((R == 2 && C <= 4) || (R == 3 && C <= 3)) {
    cout << dict::IMPOSSIBLE ln;
    return;
  }

  cout << dict::POSSIBLE ln;

  if(C == 4) {
    if(R == 4) {
      times(4, j) times(R, i) {
        out(i, (4 - j) % 4 ^ (i % 2 == 0 ? 0 : 2));
      }
    } else {
      times(4, j) times(R, i) {
        out(i, j ^ (i % 2 == 0 ? 0 : 2));
      }
    }
  } else {
    times(R / 2, ih) times(C, j) {
      out(ih * 2, (j + 2) % C);

      if(R % 2 == 1 && ih == R / 2 - 1) {
        out(ih * 2 + 2, (j + 3) % C);
      }

      out(ih * 2 + 1, j);
    }
  }
}

/* <rab:gen/> */
