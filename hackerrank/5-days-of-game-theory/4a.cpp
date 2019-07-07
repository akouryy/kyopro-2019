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
  int T; cin >> T;
  times(T, i) {
    int N; cin >> N;
    vec<int> A(N), B(N);
    vec<pair<int, int>> ab;
    times(N, i) cin >> A[i];
    times(N, i) cin >> B[i];
    times(N, i) {
      ab.push_back({A[i] + B[i], A[i]});
    }
    sort(begin(ab), end(ab));

    int ap = 0, bp = 0;
    times(N, i) {
      if(i % 2 == 0) {
        ap += ab[N+~ i].second;
      } else {
        bp += ab[N+~ i].first - ab[N+~ i].second;
      }
    }

    cout << (ap > bp ? "First" : ap < bp ? "Second" : "Tie") ln;
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
