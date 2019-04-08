/* <rab:include(base.hpp)> */
#pragma GCC optimize ("O3")
#ifdef GCJ_CASE
  void solve(long long case_id);
#else
  void solve(); /* この関数に問題ごとの処理を書く */
#endif

#if defined(EBUG) && !defined(ONLINE_JUDGE)
  #define debug true
#else
  #define NDEBUG /* <cassert>のincludeより前に定義する必要がある */
  #define debug false
#endif
#include<algorithm>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<type_traits>
#include<vector>
#ifdef __cpp_lib_execution
  #include<execution>
#endif
#include<cassert>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define int LL /* 標準ライブラリのincludeが終わってから書き換える */
#define CS const
#define CX constexpr
#define IL inline
#define RT return
#define TL template
#define TN typename
#define lambda [&]
#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(auto rab_base_dest = (t), i = (TN remove_reference<decltype(t)>::type)(f); i <= rab_base_dest; i++)
#define uptil(f, t, i)   for(auto rab_base_dest = (t), i = (TN remove_reference<decltype(t)>::type)(f); i <  rab_base_dest; i++)
#define downto(f, t, i)  for(auto rab_base_dest = (TN remove_reference<decltype(f)>::type)(t), i = (f); i >= rab_base_dest; i--)
#define downtil(f, t, i) for(auto rab_base_dest = (TN remove_reference<decltype(f)>::type)(t), i = (f); i >  rab_base_dest; i--)
#define iter(v) begin(v), end(v)
#define citer(v) cbegin(v), cend(v)
#if debug
  #define _GLIBCXX_DEBUG
  #define _LIBCPP_DEBUG 2
  #define _LIBCPP_DEBUG2 2
  #define ln << endl
#else
  #define ln << '\n'
#endif
#define tb << '\t'
#define sp << ' '
#ifdef __cpp_lib_execution
  #if debug
    #define PARABLE execution::par_unseq,
  #else
    #define PARABLE execution::seq,
  #endif
#else
  #define PARABLE /* none */
#endif
/* <rab:include(mod.hpp)> */
#ifdef MOD
  #if !defined(FORCE_MOD) && MOD != 1000000007 && MOD != 1000000009 && MOD != 998244353
    #error unknown mod MOD; if you really want to use (MOD) as mod, define FORCE_MOD.
  #endif
#else
  #define MOD 1000000007
#endif
/* <rab:include(power.hpp)> */
using int128=__int128;
TL<class T> T power(T x,int n){T rt(1);for(;n;n/=2){if(n%2)rt*=x;x*=x;}RT rt;}
int pow_mod(int x,int n,int m){int rt=1;for(;n;n/=2){if(n%2)rt=rt*x%m;x=x*x%m;}RT rt;}
int pow_mod_64(int128 x,int n,int m){int128 rt=1;for(;n;n/=2){if(n%2)rt=rt*x%m;x=x*x%m;}RT rt;}
/* </rab:include(power.hpp)> */
IL CX int modulo(int a,int m){RT(a%=m,a>=0?a:a+m);}
TL<ULL mod=MOD>class MInt{
  /*
    int with modulo.
    // `mod` must be a prime for `log`.
    `mod` must be coprime to `val` for `inv` and to `m.val` for `operator/` and `operator/=`.
  */
  /*! https://ei1333.github.io/luzhiled/snippets/other/mod-int.html */
public:
  int val;
  CX MInt():val(0){}
  explicit CX MInt(int v):val(modulo(v,mod)){}
  MInt&operator+=(CS MInt&m){val+=m.val;if(val>=mod)val-=mod;RT*this;}
  MInt&operator-=(CS MInt&m){val-=m.val;if(val<0)val+=mod;RT*this;}
  MInt&operator*=(CS MInt&m){val=val*m.val%mod;RT*this;}
  MInt&operator/=(CS MInt&m){val=val*m.inv().val%mod;RT*this;}
  MInt operator+(CS MInt&m)CS{RT MInt(*this)+=m;}
  MInt operator-(CS MInt&m)CS{RT MInt(*this)-=m;}
  MInt operator*(CS MInt&m)CS{RT MInt(*this)*=m;}
  MInt operator/(CS MInt&m)CS{RT MInt(*this)/=m;}
  MInt operator-()CS{MInt m;m.val=val?mod-val:0;RT m;}
  bool operator==(CS MInt&m)CS{RT val==m.val;}
  bool operator!=(CS MInt&m)CS{RT val!=m.val;}
  //MInt pow(int n)CS{MInt x(*this),rt(1);while(n){if(n%2)rt*=x;x*=x;n/=2;}RT rt;}
  MInt pow(int n)CS{RT power(*this,n);}
  MInt inv()CS{int a=val,b=mod,x=1,y=0,t;while(b){t=a/b;swap(b,a-=t*b);swap(y,x-=t*y);}RT(MInt)x;}
  friend ostream&operator<<(ostream&o,CS MInt<mod>&m){RT o<<m.val;}
  friend istream&operator>>(istream&i,MInt<mod>&m){int v;i>>v;m=MInt<mod>(v);RT i;}
};
using mint=MInt<>;

constexpr mint operator"" _m(ULL n){RT mint(n);}
constexpr MInt<998244353>operator"" _m998244353(ULL n){RT MInt<998244353>(n);}
constexpr MInt<1000000007>operator"" _m1e9_7(ULL n){RT MInt<1000000007>(n);}
constexpr MInt<1000000009>operator"" _m1e9_9(ULL n){RT MInt<1000000009>(n);}

//#pragma rab:gsub \b(\d+)m\b mint(\1)
/* </rab:include(mod.hpp)> */
/* <rab:include(typedefs.hpp)> */
struct unit{};

using int128=__int128;
using LD=long double;
TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;
TL<TN T>using vvvec=vec<vvec<T>>;
TL<TN T>using vvvvec=vec<vvvec<T>>;

//#pragma rab typedefs.dynamic
using VI = vec<int>; using HII = map<int, int>; using VPII = vec<pair<int, int>>; 
/* </rab:include(typedefs.hpp)> */
/* <rab:include(alias.hpp)> */
#define MP make_pair
#define MU make_unique
#define PB push_back
#define UP unique_ptr
#define foldl accumulate
#define scanl partial_sum
/* </rab:include(alias.hpp)> */

TL<TN T>IL bool amax(T&v,CS T&a){RT v<a&&(v=a,true);}
TL<TN T>IL bool amin(T&v,CS T&a){RT v>a&&(v=a,true);}

namespace kpl {
  TL<TN V, TN W>
  static IL void append(V& v, const W& w) { copy(PARABLE citer(w), back_inserter(v)); }

  TL<TN V>
  static IL auto flatten(const V& xss, int reserve_size = 0) -> TN V::value_type {
    decltype(flatten(xss)) ret;
    ret.reserve(reserve_size);
    for(const auto& xs : xss) append(ret, xs);
    ret.shrink_to_fit();
    return move(ret);
  }

  TL<TN I>
  static IL bool is_in(I x, I l, I r) {
    return l <= x && x < r;
  }
}
/* <rab:include(util.hpp)> */
#ifndef __cpp_lib_exchange_function
  // #define __cpp_lib_exchange_function 201304L
  #define exchange exchange_RAB
  TL<class T, class U=T> T exchange(T& t, U&& u) {
    T ret = move(t); t = forward<U>(u); RT ret;
  }
#endif
#ifndef __cpp_lib_clamp
  // #define __cpp_lib_clamp 201603L
  #define clamp clamp_RAB
  TL<class T> CX CS T& clamp(CS T& a, CS T& mn, CS T& mx) {
    RT a < mn ? mn : a > mx ? mx : a;
  }
#endif
TL<class V>IL void uniq_after_sort(V&v){v.erase(unique(iter(v)),v.end());}
TL<class V>IL void sort_and_uniq(V&v){sort(iter(v));v.erase(unique(iter(v)),v.end());}
TL<class V,class K>IL auto leftmost_ge(CS V&v,CS K&k){RT v.lower_bound(k);}
TL<class V,class K>IL auto leftmost_gt(CS V&v,CS K&k){RT v.upper_bound(k);}
/* </rab:include(util.hpp)> */
/* <rab:include(debug.hpp)> */
TL<class T>
IL istream&operator>>(istream&s,vec<T>&v){for(auto&&p:v)s>>p;RT s;}
TL<class T,class S>
IL ostream&operator<<(ostream&s,CS pair<T,S>&p){RT s<<"("<<p.first<<","<<p.second<<")";}
TL<class T>
IL ostream&operator<<(ostream&,CS vec<T>&);
TL<class T,class S>
IL ostream&operator<<(ostream&,CS map<T,S>&);
#define DEFINE_ITER_OUTPUT(s,x,sep){int i=0;for(CS auto&x##0_elem:x){if(i++)s<<sep;s<<x##0_elem;}RT s;}
TL<class T>
IL ostream&operator<<(ostream&s,CS vec<T>&v)DEFINE_ITER_OUTPUT(s,v,' ')
TL<class T,class S>
IL ostream&operator<<(ostream&s,CS map<T,S>&m)DEFINE_ITER_OUTPUT(s,m,' ')
TL<class T>
IL ostream&operator<<(ostream&s,CS vec<vec<T>>&w)DEFINE_ITER_OUTPUT(s,w,'\n')
TL<class T,class S>
IL ostream&operator<<(ostream&s,CS vec<map<T,S>>&v)DEFINE_ITER_OUTPUT(s,v,'\n')
/* </rab:include(debug.hpp)> */

signed main() {
  if(debug) cerr << "MOD: " << (MOD) ln;
  if(!debug) {
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
  cout << fixed << setprecision(20);
  cerr << fixed << setprecision(20);

  #ifdef GCJ_CASE
    int T; cin >> T;
    times(T, t) {
      cout << "Case #" << t + 1 << ": ";
      solve(t);
    }
  #else
    solve();
  #endif

  return 0;
}
/* </rab:include(base.hpp)> */
/* <rab:include(graph.hpp)> */
/* <rab:include(uf.hpp)> */

template<class T = int, class Adder = plus<T>, class Inverser = negate<T>>
class UnionFind {
  /*
    ポテンシャル付きUnionFind (find: path compression, merge: union by size)

    FUNC:
      merge: 既にマージされていたならfalse, 今回マージ処理を行ったならtrueを返す.

    TIME:
      new, clear:           O(n).
      root, merge, is_same: 償却O(a(n)); ただしaはアッカーマン関数の逆関数.

    TMPL:
      T: ポテンシャルの型
      Adder: ポテンシャルの和演算 (群の演算)
      Inverser: ポテンシャルの逆元関数
      例: UnionFind<int, bit_xor<int>, identity<int>>
  */
  /*!
    http://noshi91.hatenablog.com/entry/2018/05/30/191943
    https://en.wikipedia.org/wiki/Disjoint-set_data_structure
    https://qiita.com/drken/items/cce6fc5c579051e64fab
  */

  int n, *parents, *sizes;
  T *pot_diffs;
  bool to_delete;
  Adder adder;
  Inverser inverser;

public:
  UnionFind(int n, bool to_delete = false):
    n(n), parents(new int[n]), sizes(new int[n]), pot_diffs(new T[n]), to_delete(to_delete)
  {
    clear();
  }

  void clear() {
    times(n, i) parents[i] = i; /* roots */
    fill(sizes, sizes + n, 1);
    fill(pot_diffs, pot_diffs + n, 0);
  }

  ~UnionFind(){if(to_delete){delete[]parents;delete[]sizes;delete[]pot_diffs;}}

  int size() { return n; }

  int root(int i) {
    int p = parents[i];
    if(p == i) return i; /* `i` is a root */
    int r = root(p); /* and pot_diffs[p] := diff from root */
    pot_diffs[i] += pot_diffs[p];
    parents[i] = r;
    return r;
  }

  bool is_same(int i,int j){RT root(i)==root(j);}
  bool is_all_same(){int r=root(0);uptil(1,n,i)if(root(i)!=r)RT 0;RT 1;}

  bool merge(int i, int j, T pdiff = 0) {
    i = root(i);
    j = root(j);
    if(i == j) return false; /* already merged */
    if(sizes[i] > sizes[j]) {
      swap(i, j);
      pdiff = inverser(pdiff);
    }
    /* now sizes[i] <= sizes[j] */
    parents[i] = j;
    sizes[j] += sizes[i];
    pot_diffs[i] = pdiff;
    return true;
  }

  T diff(int i, int j) {
    root(i); /* pot_diffs[i] := diff from root */
    root(j); /* pot_diffs[j] := diff from root */
    return adder(pot_diffs[i], inverser(pot_diffs[j]));
  }
};
using unionfind=UnionFind<>;
/* </rab:include(uf.hpp)> */

template<class EdgeVal>
struct Edge {
  int from; int to;
  EdgeVal weight;

  Edge(int from, int to, EdgeVal weight): from(from), to(to), weight(weight) {}
  IL bool operator==(CS Edge&e)CS{RT weight==e.weight&&from==e.from&&to==e.to;}
  IL bool operator<(CS Edge&e)CS{RT weight<e.weight||(weight==e.weight&&(from<e.from||(from==e.from&&to<e.to)));}
  IL bool operator<=(CS Edge&e)CS{RT this==e||this<e;}
  IL bool operator>(CS Edge&e)CS{RT e<this;}
  IL bool operator>=(CS Edge&e)CS{RT e<=this;}
};

template<class VtxVal, class EdgeVal>
class Graph {
  using VoidWithoutEdgeVal=TN enable_if<is_default_constructible<EdgeVal>::value,void>::type;
protected:
  int nv_, nde_;
  unionfind uf;
public:
  vec<VtxVal> vs;
  vvec<Edge<EdgeVal>> edges;

  Graph(int nv): nv_(nv), nde_(0), uf(nv), vs(nv), edges(nv) {}

  IL int nv()CS{RT nv_;}
  IL int nde()CS{RT nde_;}
  IL int nue()CS{RT nde_/2;}

  IL void add_dedge(int i, int j, const EdgeVal& val) {
    if(!kpl::is_in(i, 0LL, nv_) || !kpl::is_in(j, 0LL, nv_)) {
      cerr << "invalid index: (" << i << ", " << j << ") for Graph(nv = " << nv_ << ")" ln;
      exit(1);
    }
    edges[i].emplace_back(i, j, val);
    ++nde_;
  }
  IL VoidWithoutEdgeVal add_dedge(int i, int j) {
    add_dedge(i, j, EdgeVal());
  }

  IL void add_uedge(int i, int j, const EdgeVal& val) {
    add_dedge(i, j, val);
    add_dedge(j, i, val);
  }
  IL VoidWithoutEdgeVal add_uedge(int i, int j) {
    add_uedge(i, j, EdgeVal());
  }

  IL bool is_connected(){
    uf.clear();
    for(CS auto&es:edges)for(CS auto&e:es)uf.merge(e.from,e.to);
    RT uf.is_all_same();
  }
};
/* </rab:include(graph.hpp)> */
/* <rab:include(kruskal.hpp)> */

namespace rab {
  /**
   * Verified:
   *   - with max_edges: https://atcoder.jp/contests/cf17-tournament-round2-open/submissions/4886659
   */
  TL<TN V, TN E> Graph<V, E> kruskal_with_sorted_edge(
    const Graph<V, E>& g,
    const vector<Edge<E>>& es,
    int max_edges = -1
  ) {
    if(max_edges < 0) max_edges += g.nv();

    Graph<V, E> t(g.nv());
    unionfind uf(g.nv());

    for(const auto& e : es) {
      int i = e.from, j = e.to;
      if(uf.merge(i, j)) { /* true: 今まで違う木に属していた */
        t.add_uedge(i, j, e.weight);

        --max_edges;
        if(max_edges == 0) break;
      }
    }

    return t;
  }

  TL<TN V, TN E> IL Graph<V, E> kruskal(const Graph<V, E>& g, int max_edges = -1) {
    vec<Edge<E>> edges = kpl::flatten(g.edges, g.nde());
    sort(iter(edges));
    return kruskal_with_sorted_edge(g, edges, max_edges);
  }
}
/* </rab:include(kruskal.hpp)> */

void solve() {
// NMKN(-C)M(-A-BW)
/* <foxy.memo-area> */
int N;int M;int K;cin>>N;cin>>M;cin>>K;VI C(N);times(N,Ri_0){cin>>C[Ri_0];--C[
Ri_0];}VI A(M);VI B(M);VI W(M);times(M,Ri_0){cin>>A[Ri_0];--A[Ri_0];cin>>B[Ri_0]
;--B[Ri_0];cin>>W[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit, int> g(N);
  times(M, j) g.add_uedge(A[j], B[j], W[j]);

  case12: {
    times(N, i) if(C[i] == -1) goto case3;
    HII cnt; times(N, i) ++cnt[C[i]];
    times(K, c) if(cnt[c] == 0) {
      cout << -1 ln; return;
    }

    VPII x(N); times(N, i) x[i] = { C[i], i };
    sort(iter(x));
    times(N - 1, k) if(x[k].first == x[k + 1].first) {
      g.add_uedge(x[k].second, x[k + 1].second, 0);
    }

    auto kr = rab::kruskal(g);
    if(!kr.is_connected()) {
      cout << -1 ln;
      return;
    }
    int ans2 = 0;
    times(N, i) for(auto& e : kr.edges[i]) {
      ans2 += e.weight; // weight * 2
    }
    cout << ans2 / 2 ln;
  }
  return;

  case3: {
    times(N, i) if(C[i] != -1) goto case4;

    auto kr = rab::kruskal(g, K - 1);
    if(kr.nue() != K - 1) {
      cout << -1 ln;
      return;
    }

    int ans2 = 0;
    times(N, i) for(auto& e : kr.edges[i]) {
      ans2 += e.weight; // weight * 2
    }
    cout << ans2 / 2 ln;
  }
  return;

  case4:;
}

/* <rab:gen/> */
