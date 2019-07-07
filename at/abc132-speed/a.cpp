#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define uptil(a, b, i) for(int i = (a), b_ = (b); i < b_; ++i)
#define upto(a, b, i) for(int i = (a), b_ = (b); i <= b_; ++i)
#define downtil(a, b, i) for(int i = (a), b_ = (b); i > b_; --i)
#define downto(a, b, i) for(int i = (a), b_ = (b); i >= b_; --i)
#define times(n, i) uptil(0, n, i)
#define rtimes(n, i) downto((n)-1, 0, i)

#define sp <<" "
#define ln <<"\n"
#define size(v) ((int)(v).size())
template<class T> using vec=vector<T>;
template<class T> using vvec=vec<vector<T>>;

void solve() {
  map<char, int> s;
  times(4, i) {
    char c; cin >> c; ++s[c];
  }
  for(auto i : s) {
    if(i.second != 2) {
      cout << "No" ln;
      goto next_case;
    }
  }

  cout << "Yes" ln;
  next_case:;
}

signed main() {
  // cin.tie(0);
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(10);
  solve();
  return 0;
}
