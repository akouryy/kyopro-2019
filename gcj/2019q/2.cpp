#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve(int gcj_case_id) {
// N "P"
/* <foxy.memo-area> */
int N;string P;cin>>N;cin>>P;
/* </foxy.memo-area> */

  bool rev = P[P.size() - 1] == 'S';
  if(rev) {
    for(char& c : P) c = c == 'S' ? 'E' : 'S';
  }

  map<PII, char> enemy;
  {
    int i = 0, j = 0;
    for(char& c : P) {
      enemy[{i, j}] = c;
      if(c == 'S') {
        ++j;
      } else {
        ++i;
      }
    }
  }

  VC ans; ans.reserve(P.size());
  {
    int i = 0, j = 0;
    times(P.size(), k) {
      if(enemy[{i, j}] == 'E' || i == N - 1) {
        ans.push_back('S');
        ++j;
      } else { // 'S' or null
        ans.push_back('E');
        ++i;
      }
    }
  }

  if(rev) {
    for(char& c : ans) c = c == 'S' ? 'E' : 'S';
  }

  cout << string(iter(ans)) ln;
}
