/* <rab:include(base.hpp)> */
#pragma GCC optimize ("O3")
void solve(); /* この関数に問題ごとの処理を書く */

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
#include<vector>
#ifdef __cpp_lib_execution
  #include<execution>
#endif
#include<cassert>
#include<cstdio>
#include<cstdlib>

using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define int LL /* 標準ライブラリのincludeが終わってから書き換える */
#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(auto rab_base_dest = (t), i = decltype(t)(f); i <= rab_base_dest; i++)
#define uptil(f, t, i)   for(auto rab_base_dest = (t), i = decltype(t)(f); i <  rab_base_dest; i++)
#define downto(f, t, i)  for(auto rab_base_dest = decltype(f)(t), i = (f); i >= rab_base_dest; i--)
#define downtil(f, t, i) for(auto rab_base_dest = decltype(f)(t), i = (f); i >  rab_base_dest; i--)
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
TL<class T> T power(T x,int n){T rt(1);for(;n;n/=2){if(n%2)rt*=x;x*=x;}RT rt;}
int pow_mod(int x,int n,int m){int rt=1;for(;n;n/=2){if(n%2)rt=rt*x%m;x=x*x%m;}RT rt;}
//int pow_mod_64(int128 x,int n,int m){int128 rt=1;for(;n;n/=2){if(n%2)rt=rt*x%m;x=x*x%m;}RT rt;}
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

/* @rab:typedefs:dynamic */
using VM = vec<mint>; 
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
template<class V> void uniq_after_sort(V& v) { v.erase(unique(iter(v)), v.end()); }
template<class V> void sort_and_uniq(V& v) { sort(iter(v)); v.erase(unique(iter(v)), v.end()); }
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

  solve();

  return 0;
}
/* </rab:include(base.hpp)> */
/* <rab:include(nck.hpp)> */
/* <rab:include(fact.hpp)> */

/*! https://twitter.com/meguru_comp/status/694207919517077504 */
VM fact, fact_inv;
inline void fact_init(int n) {
  int a = fact.size();
  if(a > n) return;
  fact.resize(n+1);
  fact_inv.resize(n+1);
  if(a == 0) {
    fact[a] = fact_inv[a] = mint(1);
    ++a;
  }
  upto(a, n, i) fact[i] = fact[i-1] * mint(i);
  fact_inv[n] = fact[n].inv();
  downto(n-1, a, i) fact_inv[i] = fact_inv[i+1] * mint(i+1);
}
/* </rab:include(fact.hpp)> */

/*! https://twitter.com/meguru_comp/status/694547019885449216 */
inline mint nCk(int n, int k, bool check_init = true) {
  /*-
    verification: ok
    https://atcoder.jp/contests/keyence2019/submissions/4015435
    https://atcoder.jp/contests/arc004/submissions/4016291
  */
  if(check_init && fact.size() <= n) fact_init(n);
  if(0 <= k && k <= n) return fact[n] * fact_inv[k] * fact_inv[n-k];
  else return mint(0);
}
inline mint nPk(int n, int k, bool check_init = true) {
  /*-
    verification: 1 fix not verified
    https://atcoder.jp/contests/keyence2019/submissions/4015435
  */
  if(check_init && fact.size() <= n) fact_init(n);
  if(0 <= k && k <= n) return fact[n] * fact_inv[n-k];
  else return mint(0);
}
/* </rab:include(nck.hpp)> */

void solve() {
// BW
/* <foxy.memo-area> */
int B;int W;cin>>B;cin>>W;
/* </foxy.memo-area> */

  bool bad = B < W;
  if(bad) swap(B, W);

  mint half = 1_m / 2_m;

  times(W, i) cout << half ln;

  mint pyon = 1_m / 2_m .pow(W);
  uptil(W, B, i) {
    mint a = pyon + (1_m - pyon) / 2_m;
    cout << (bad ? 1_m - a : a) ln;

    pyon += nCk(i, W - 1) / 2_m .pow(i + 1);
  }

  mint qyon = 1_m / 2_m .pow(B);
  uptil(B, B + W, i) {
    mint a = pyon + (1_m - pyon - qyon) / 2_m;
    cout << (bad ? 1_m - a : a) ln;

    pyon += nCk(i, W - 1) / 2_m .pow(i + 1);
    qyon += nCk(i, B - 1) / 2_m .pow(i + 1);
  }
}

/* <rab:gen/> */