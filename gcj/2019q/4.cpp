//#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

void solve_task(int task_id) {
// NBF
/* <foxy.memo-area> */
int N;int B;int F;cin>>N;cin>>B;cin>>F;
/* </foxy.memo-area> */

  VI pieces(64);
  VC cmd(1024);

  {
    times(64, i) times(16, j) cmd[i * 16 + j] = '0' + i % 2;

    cout << string(begin(cmd), begin(cmd) + N) << endl;
    string T; cin >> T;

    int p = 0, ps = 0;
    times(64, i) {
      while(ps < N && T[ps] == '0' + i % 2) { ++p; ++ps; }
      pieces[i] = p;
      p = 0;
    }
  }

  dd pieces;

  VS pyon(4);
  times(4, f) {
    int sz = 1 << (3 - f);
    times(1024 / sz, i) times(sz, j) cmd[i * sz + j] = '0' + i % 2;

    cout << string(begin(cmd), begin(cmd) + N) << endl;
    cin >> pyon[f];
  }

  dd pyon;

  bool sp_flag = false;
  int sy = 0;
  times(64, i) {
    VI ok(pieces[i]);
    times(4, f) {
      times(pieces[i], j) {
        if(sy + j < N - B) {
          ok[j] += (pyon[f][sy + j] - '0') << (3 - f);

          if(i == 62) {
            dd f; j; sy + j; pyon[f][sy + j]; ok[j];
          }
        } else {
          ok[j] = 10000;
        }
      }
    }
    sy += pieces[i];
    dd i; ok;
    times(16, j) {
      int x = i * 16 + j;
      if(find(iter(ok), j) == end(ok) && x < N) {
        if(sp_flag) cout sp;
        cout << x;
        sp_flag = true;
      }
    }
  }
  cout << endl;
  int AC; cin >> AC; if(AC == -1) exit(0);
}

void solve() {
  int T;cin>>T;times(T,i)solve_task(i);
}
