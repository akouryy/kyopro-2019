//#define GCJ_CASE
#include "base.hpp"
//#include "consts.hpp"

int xgcd(int a, int b, int &p, int &q) {
    if(b == 0) { p = 1; q = 0; return a; }
    int d = xgcd(b, a % b, q, p);
    q -= a / b * p;
    return d;
}

PII chinese(int b1, int m1, int b2, int m2) {
  int p, q;
  int d = xgcd(m1, m2, p, q);
  if((b2 - b1) % d != 0) return {0, 0};

  int m = m1 * (m2 / d);
  int tmp = (b2 - b1) / d * p % (m2 / d);
  int r = modulo(b1 + m1 * tmp, m);
  return {r, m};
}

void solve() {
  int T;
  cin >> T;
  int N, M; cin >> N >> M;

  times(T, t) {
    upto(12, 18, x) {
      times(18, y) {
        cout << (y ? " " : "") << x;
      }
      cout ln;
    }
    cout.flush();

    VI res(19);
    upto(12, 18, x) {
      int s = 0;
      times(18, y) {
        cin >> s;
        res[x] += s;
      }
    }

    dd res;

    int r = res[12], m = 12;
    dd r; m;
    upto(13, 18, x) {
      tie(r, m) = chinese(r, m, res[x], x);
      dd r; m;
    }

    if(r == 0) exit(1);

    cout << r << endl;

    int pyon;
    cin >> pyon;
    if(pyon == -1) volatile int* k = new int[1 << 30];
  }
}
