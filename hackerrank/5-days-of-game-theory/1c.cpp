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

void solve() {
  vvec<int> gr(15, vec<int>(15));

  times(30, k) {
    times(15, i) {
      int j = k - i;
      if(0 <= j && j <= 14) {
        int g = 0;
        while(
          i >= 1  && j >= 2  && gr[i-1][j-2] == g ||
          i <= 13 && j >= 2  && gr[i+1][j-2] == g ||
          i >= 2  && j >= 1  && gr[i-2][j-1] == g ||
          i >= 2  && j <= 13 && gr[i-2][j+1] == g
        ) ++g;
        gr[i][j] = g;
      }
    }
  }

  times(15, i) {
    times(15, j) cerr << gr[i][j] sp;
    cerr ln;
  }

  int T; cin >> T;
  times(T, i) {
    int X, Y; cin >> X >> Y;
    cout << (gr[X-1][Y-1] ? "First" : "Second") ln;
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
