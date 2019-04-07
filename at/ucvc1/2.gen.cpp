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
#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(auto rab_base_dest = (t), i = (typename remove_reference<decltype(t)>::type)(f); i <= rab_base_dest; i++)
#define uptil(f, t, i)   for(auto rab_base_dest = (t), i = (typename remove_reference<decltype(t)>::type)(f); i <  rab_base_dest; i++)
#define downto(f, t, i)  for(auto rab_base_dest = (typename remove_reference<decltype(f)>::type)(t), i = (f); i >= rab_base_dest; i--)
#define downtil(f, t, i) for(auto rab_base_dest = (typename remove_reference<decltype(f)>::type)(t), i = (f); i >  rab_base_dest; i--)
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
#define CS const
#define CX constexpr
#define IL inline
#define RT return
#define TL template
#define TN typename
#define lambda [&]
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
  template<class V, class W>
  static IL void append(V& v, const W& w) { copy(PARABLE citer(w), back_inserter(v)); }

  template<class V>
  static IL auto flatten(const V& xss, unsigned reserve_size = 0) -> vector<decltype(*begin(*begin(xss)))> {
    decltype(flatten(xss)) ret;
    ret.reserve(reserve_size);
    for(const auto& xs : xss) append(ret, xs);
    ret.shrink_to_fit();
    return move(ret);
  }

  template<class I>
  static inline bool is_in(I x, I l, I r) {
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

template<class EdgeVal>
using Edge = tuple<EdgeVal, int, int>;

template<class VtxVal, class EdgeVal = unit>
class Graph {
protected:
  int nv_, ne_;
public:
  vec<VtxVal> vs;
  vec<vec<Edge<EdgeVal>>> edges;

  Graph(int nv): nv_(nv), ne_(0), vs(nv), edges(nv) {}

  int nv()CS{RT nv_;}
  int ne()CS{RT ne_;}

  void add_dedge(int i, int j, const EdgeVal& val) {
    if(!kpl::is_in(i, 0LL, nv_) || !kpl::is_in(j, 0LL, nv_)) {
      cerr << "invalid index: (" << i << ", " << j << ") for Graph(nv = " << nv_ << ")" ln;
      exit(1);
    }
    edges[i].emplace_back(val, i, j);
    ++ne_;
  }
  typename enable_if<is_default_constructible<EdgeVal>::value,void>::type add_dedge(int i, int j) {
    add_dedge(i, j, EdgeVal());
  }

  void add_uedge(int i, int j, const EdgeVal& val) {
    add_dedge(i, j, val);
    add_dedge(j, i, val);
  }
  typename enable_if<is_default_constructible<EdgeVal>::value,void>::type add_uedge(int i, int j) {
    add_uedge(i, j, EdgeVal());
  }
};
/* </rab:include(graph.hpp)> */
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

  unsigned n, *parents, *sizes;
  T *pot_diffs;
  Adder adder;
  Inverser inverser;

public:
  UnionFind(unsigned n):
    n(n), parents(new unsigned[n]), sizes(new unsigned[n]), pot_diffs(new T[n])
  {
    clear();
  }

  void clear() {
    times(n, i) parents[i] = i; /* roots */
    fill(sizes, sizes + n, 1);
    fill(pot_diffs, pot_diffs + n, 0);
  }

  #ifdef RAB_DESTRUCT
    ~UnionFind() { delete[] parents; delete[] sizes; delete[] pot_diffs; }
  #endif

  unsigned size() { return n; }

  unsigned root(unsigned i) {
    unsigned p = parents[i];
    if(p == i) return i; /* `i` is a root */
    unsigned r = root(p); /* and pot_diffs[p] := diff from root */
    pot_diffs[i] += pot_diffs[p];
    parents[i] = r;
    return r;
  }

  bool is_same(unsigned i, unsigned j) { return root(i) == root(j); }

  bool merge(unsigned i, unsigned j, T pdiff = 0) {
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

  T diff(unsigned i, unsigned j) {
    root(i); /* pot_diffs[i] := diff from root */
    root(j); /* pot_diffs[j] := diff from root */
    return adder(pot_diffs[i], inverser(pot_diffs[j]));
  }
};
using unionfind=UnionFind<>;
/* </rab:include(uf.hpp)> */

namespace kpl {
  template<class V, class E>
  Graph<V, E> kruskal_with_sorted_edgeX(const Graph<V, E>& g, const vector<Edge<E>>& es, int x) {
    Graph<V, E> t(g.nv());
    unionfind uf(g.nv());

    for(const auto& e : es) {
      E cost; unsigned i, j; tie(cost, i, j) = e;
      if(uf.merge(i, j)) { /* true: 今まで違う木に属していた */
        t.add_uedge(i, j, cost);
        --x;
        if(x == 0) return t;
      }
    }

    uptil(1, g.nv(), i) if(!uf.is_same(0, i)) {
      throw -1ll;
    }

    return t;
  }

  template<class V, class E>
  Graph<V, E> kruskalX(const Graph<V, E>& g, int x) {
    // vec<Edge<E>> edges = kpl::flatten(g.edges, g.ne());
    vec<Edge<E>> ret;
    ret.reserve(g.ne());
    for(const auto& xs : g.edges) append(ret, xs);
    ret.shrink_to_fit();
    auto edges = ret;

    sort(iter(edges));
    return kruskal_with_sorted_edgeX(g, edges, x);
  }
}

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

    try {
      auto kr = kpl::kruskalX(g, N);
      int ans2 = 0;
      times(N, i) for(auto& e : kr.edges[i]) {
        ans2 += get<0>(e); // weight * 2
      }
      cout << ans2 / 2 ln;
    } catch(int not_connected) {
      cout << -1 ln;
    }
  }
  return;

  case3: {
    times(N, i) if(C[i] != -1) goto case4;
    try {
      auto kr = kpl::kruskalX(g, K - 1);
      int ans2 = 0;
      times(N, i) for(auto& e : kr.edges[i]) {
        ans2 += get<0>(e); // weight * 2
      }
      cout << ans2 / 2 ln;
    } catch(int not_connected) {
      cout << -1 ln;
    }
  }
  return;

  case4:;
}

/* <rab:gen/> */
