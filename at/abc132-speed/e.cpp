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

constexpr int mod = 1e9 + 7;

void solve() {
  int N, M; cin >> N >> M;
  vvec<int> edges(N);
  times(M, i) {
    int U, V; cin >> U >> V;
    edges[--U].push_back(--V);
  }
  int S, T; cin >> S >> T; --S; --T;

  priority_queue<pair<int, int>> pq;
  pq.emplace(-0, S * 3);
  vec<int> dist(N * 3, 1LL << 50);

  while(!pq.empty()) {
    int d = -pq.top().first, v = pq.top().second; pq.pop();
    if(d >= dist[v]) continue;
    dist[v] = d;
    for(int u : edges[v / 3]) {
      pq.emplace(-(d + 1), u * 3 + (v + 1) % 3);
    }
  }

  cout << (dist[T * 3] == (1LL << 50) ? -1 : dist[T * 3] / 3) ln;
}

signed main() {
  // cin.tie(0);
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(10);
  solve();
  return 0;
}
