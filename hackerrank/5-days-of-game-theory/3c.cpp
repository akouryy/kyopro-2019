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

int gr[30][30][31][31];
int s[31][31];

void solve() {
  int T; cin >> T;
  times(T, i) {
    int N; cin >> N;
    times(N, i) times(N, j) {
      int A; cin >> A;
      s[i+1][j+1] =
        (A == 1 || A == 4 || A == 6 || A == 8 || A == 9)
        + s[i][j+1] + s[i+1][j] - s[i][j];
    }

    upto(1, N, di) upto(1, N, dj) upto(0, N-di, i) upto(0, N-dj, j) {
      if(s[i+di][j+dj] - s[i][j+dj] - s[i+di][j] + s[i][j] == 0) {
        // all prime
        gr[i][j][i+di][j+dj] = 0;
        continue;
      }
      int k = 0;
      upto(1, di-1, ei) {
        k |= 1LL << (gr[i][j][i+ei][j+dj] ^ gr[i+ei][j][i+di][j+dj]);
      }
      upto(1, dj-1, ej) {
        k |= 1LL << (gr[i][j][i+di][j+ej] ^ gr[i][j+ej][i+di][j+dj]);
      }
      int kb = 0;
      while((k >> kb) & 1) ++kb;
      gr[i][j][i+di][j+dj] = kb;
    }

    /*times(N, i) {
      times(N, j) cerr << gr[0][0][i+1][j+1] sp;
      cerr ln;
    }*/

    cout << (gr[0][0][N][N] ? "First" : "Second") ln;
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
