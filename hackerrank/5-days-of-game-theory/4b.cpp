#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define int LL
#define upto(a, b, i) for(int i = (a), b_ = (b); i <= b_; ++i)
#define uptil(a, b, i) for(int i = (a), b_ = (b); i < b_; ++i)
#define downto(a, b, i) for(int i = (a), b_ = (b); i >= b_; --i)
#define downtil(a, b, i) for(int i = (a), b_ = (b); i > b_; --i)
#define times(n, i) uptil(0, n, i)
#define rtimes(n, i) downto((n) - 1, 0, i)
#define sp << " "
#define ln << "\n"
#define size(v) ((int)(v).size())
template<class T> using vec = vector<T>;
template<class T> using vvec = vec<vec<T>>;

int ms[8];
int memo[1 << 14][17];

bool p2win(bool p2turn, int rest, int m) {
  m %= 17;
  if(memo[rest][m]) return ~memo[rest][m];
  if(rest == 0) return m == 0;

  if(p2turn) {
    for(int i = 0; i < 32; ++i) if(rest >> i & 1) {
      if(p2win(false, rest & ~(1ll << i), m + ms[i % 8]) ||
         p2win(false, rest & ~(1ll << i), m - ms[i % 8] + 17)) {
        memo[rest][m] = ~1;
        return true;
      }
    }
    memo[rest][m] = ~0;
    return false;
  } else {
    for(int i = 0; i < 32; ++i) if(rest >> i & 1) {
      if(!p2win(true, rest & ~(1ll << i), m + ms[i % 8]) ||
         !p2win(true, rest & ~(1ll << i), m - ms[i % 8] + 17)) {
        memo[rest][m] = ~0;
        return false;
      }
    }
    memo[rest][m] = ~1;
    return true;
  }
}

void solve() {
  /*
  ms[0] = 2;
  upto(1, 7, i) ms[i] = ms[i - 1] * 2 % 17;

  upto(1, 32, i) {
    cout << i sp << p2win(false, (1 << i) - 1, 0) ln;
  }
  return;
  */

  int T; cin >> T;
  times(T, i) {
    int N; cin >> N;

    cout << (N % 8 ? "First" : "Second") ln;
  }
}

signed main(){
  cin.tie(0);
  cerr.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(6);
  solve();
  return 0;
}
