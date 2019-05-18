#define GCJ_CASE
#include "base.hpp"
#include "uf.hpp"
#include "consts.hpp"

// TL<TN F>
int pyon(unionfind &uf, int R, int C, const VS &S, const WC &f) {
  uf.clear();
  times(R, i) times(C, j) {
    if(S[i][j] == f[i][j]) times(4, d) {
      int ii = i + di4[d], jj = j + dj4[d];
      if(rab::is_in(ii, 0ll, R) && rab::is_in(jj, 0ll, C) && S[ii][jj] == f[ii][jj]) {
        uf.merge(i * C + j, ii * C + jj);
      }
    }
  }

  return *max_element(uf.sizes, uf.sizes + R * C);
}

bool match_pattern(const VS &S, const VS &T) {
  int rs = size(S), cs = size(S[0]), rt = size(T), ct = size(T[0]);
  upto(0, rs - rt, i) upto(0, cs - ct, j) {
    times(rt, ii) times(ct, jj) {
      if(S[i + ii][j + jj] != T[ii][jj]) goto mppyon;
    }
    return true;
    mppyon:;
  }
  return false;
}

void solve(int gcj_case_id) {
// RCR("S")
/* <foxy.memo-area> */
int R;int C;cin>>R;cin>>C;VS S(R);times(R,Ri_0){cin>>S[Ri_0];}
/* </foxy.memo-area> */

  unionfind uf(R * C);

  int ans = 0;
  WC zp(R, VC(C, 'W'));
  amax(ans, pyon(uf, R, C, S, zp));
  zp = WC(R, VC(C, 'B'));
  amax(ans, pyon(uf, R, C, S, zp));

  if(match_pattern(S, {{'W'}, {'B'}}))
    uptil(1, R, b) {
      times(R, i) times(C, j) zp[i][j] = IF(i < b, 'W', 'B');
      amax(ans, pyon(uf, R, C, S, zp));
      dd 0; ans;
    }
  if(match_pattern(S, {{'B'}, {'W'}}))
    uptil(1, R, b) {
      times(R, i) times(C, j) zp[i][j] = IF(i < b, 'B', 'W');
      amax(ans, pyon(uf, R, C, S, zp));
      dd 0; ans;
    }
  if(match_pattern(S, {{'W', 'B'}}))
    uptil(1, C, b) {
      times(R, i) times(C, j) zp[i][j] = IF(j < b, 'W', 'B');
      amax(ans, pyon(uf, R, C, S, zp));
      dd 0; ans;
    }
  if(match_pattern(S, {{'B', 'W'}}))
    uptil(1, C, b) {
      times(R, i) times(C, j) zp[i][j] = IF(j < b, 'B', 'W');
      amax(ans, pyon(uf, R, C, S, zp));
      dd 0; ans;
    }

  times(2, lu) times(2, ru) times(2, ld) times(2, rd) {
    if(match_pattern(S, {{lu ? 'W' : 'B', ru ? 'W' : 'B'}, {ld ? 'W' : 'B', rd ? 'W' : 'B'}}))
      uptil(1, R, p) uptil(1, C, q) {
        times(R, i) times(C, j) {
          zp[i][j] = IF(i < p,
            IF(j < q, lu ? 'W' : 'B', ru ? 'W' : 'B'),
            IF(j < q, ld ? 'W' : 'B', rd ? 'W' : 'B')
          );
        }
        amax(ans, pyon(uf, R, C, S, zp));
        dd 0; ans;
      }
  }

  cout << ans ln;
}
