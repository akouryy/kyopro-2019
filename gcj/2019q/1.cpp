#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int gcj_case_id) {
// "N"
/* <foxy.memo-area> */
string N;cin>>N;
/* </foxy.memo-area> */

  VC a, b;
  a.reserve(N.size());
  b.reserve(N.size());

  bool d = false;

  times(N.size(), i) {
    if(N[i] == '4') {
      a.push_back('1');
      b.push_back('3');
      d = true;
    } else {
      if(d) a.push_back('0');
      b.push_back(N[i]);
    }
  }

  cout << string(iter(a)) sp << string(iter(b)) ln;
}
