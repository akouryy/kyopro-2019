#include "base.hpp"
#include "consts.hpp"
#include "sat2.hpp"

void solve() {
  // NN("U")
  int N;cin>>N;VS U(N);times(N,Ri_0){cin>>U[Ri_0];}

  if(N > 52 * 52 + 52) {
    cout << dict::Impossible ln;
    return;
  }

  WPBI sat;
  mint x = 2_m;
  times(N, i) times(N, j) if(i != j) {
    const auto &a = U[i], &b = U[j];

    if(i < j) {
      if(a[0] == b[0]) {
        // S[i]=S[j] if !vi && !vj
        sat.PB({{true, i}, {true, j}});
        if(a[1] == b[1]) {
          // S[i]=S[j] if vi && vj
          sat.PB({{false, i}, {false, j}});
        }
      }

      if(a[2] == b[2]) {
        // T[i]=T[j] if vi && vj
        sat.PB({{false, i}, {false, j}});
        if(a[1] == b[1]) {
          // T[i]=T[j] if !vi && !vj
          sat.PB({{true, i}, {true, j}});
        }
      }
    }

    if(a[0] == b[2]) {
      // S[i] == T[j] if !vi && vj
      sat.PB({{true, i}, {false, j}});
    }
    if(a[0] == b[1] && a[1] == b[2]) {
      // S[i] == T[j] if vi && !vj
      sat.PB({{false, i}, {true, j}});
    }
  }

  auto a = sat2(N, sat);
  if(!a.first) {
    cout << dict::Impossible ln;
    return;
  }
  times(N, i) {
    if(a.second[i]) {
      cout << U[i][0] << U[i][1] sp << U[i][2] ln;
    } else {
      cout << U[i][0] sp << U[i][1] << U[i][2] ln;
    }
  }
}
