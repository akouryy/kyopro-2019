#define MOD 998244353
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
#include<limits>
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
#include<climits>
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
#define upto(f, t, i)    for(int rab_base_loop##i=(t),i=(f);i<=rab_base_loop##i;i++)
#define uptil(f, t, i)   for(int rab_base_loop##i=(t),i=(f);i< rab_base_loop##i;i++)
#define downto(f, t, i)  for(int rab_base_loop##i=(t),i=(f);i>=rab_base_loop##i;i--)
#define downtil(f, t, i) for(int rab_base_loop##i=(t),i=(f);i> rab_base_loop##i;i--)
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
using WI = vvec<int>; using VI = vec<int>; using VM = vec<mint>; 
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
  TL<TN T,TN U=T>IL T exchange(T& t, U&& u){T x=move(t);t=forward<U>(u);RT x;}
#endif
#ifndef __cpp_lib_clamp
  // #define __cpp_lib_clamp 201603L
  #define clamp clamp_RAB
  TL<TN T>IL CX CS T&clamp(CS T&a,CS T&mn,CS T&mx){RT a<mn?mn:a>mx?mx:a;}
#endif
TL<TN T>int size_RAB(T t){RT t.size();}
#define size size_RAB

TL<TN V>IL void uniq_after_sort(V&v){v.erase(unique(iter(v)),v.end());}
TL<TN V>IL void sort_and_uniq(V&v){sort(iter(v));v.erase(unique(iter(v)),v.end());}
TL<TN V,TN K>IL auto leftmost_ge(CS V&v,CS K&k){RT v.lower_bound(k);}
TL<TN V,TN K>IL auto leftmost_gt(CS V&v,CS K&k){RT v.upper_bound(k);}
namespace rab{
  /**
    verified:
      - T=int https://atcoder.jp/contests/colopl2018-final-open/submissions/4889360
  */
  TL<TN T>struct Compressed{int size;map<T,int>zip;vec<T>unzip;};
  TL<TN T>IL Compressed<T>compressed(vec<T>v){
    sort_and_uniq(v);map<T,int>zip;times(size(v),i)zip[v[i]]=i;RT{size(v),zip,move(v)};
  }
  /**
    not verified
  */
  TL<TN T>struct CompressedSrc{int size;map<T,int>zip;vec<T>unzip;WI src;};
  TL<TN T>IL CompressedSrc<T>compressed_src(CS vec<T>&v){
    auto c=compressed(v);VI src(c.size);times(size(v),i)src[c.zip[v[i]]].PB(i);RT{c.size,c.zip,c.unzip,src};
  }
}
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
/* <rab:include(nck.hpp)> */
/* <rab:include(fact.hpp)> */

/*! https://twitter.com/meguru_comp/status/694207919517077504 */
VM fact, fact_inv;
inline void fact_init(int n) {
  int a = size(fact);
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
  if(check_init && size(fact) <= n) fact_init(n);
  if(0 <= k && k <= n) return fact[n] * fact_inv[k] * fact_inv[n-k];
  else return mint(0);
}
inline mint nPk(int n, int k, bool check_init = true) {
  /*-
    verification: 1 fix not verified
    https://atcoder.jp/contests/keyence2019/submissions/4015435
  */
  if(check_init && size(fact) <= n) fact_init(n);
  if(0 <= k && k <= n) return fact[n] * fact_inv[n-k];
  else return mint(0);
}
/* </rab:include(nck.hpp)> */
//#include "consts.hpp"

mint dp[6001][3001];

void solve() {
// N X
/* <foxy.memo-area> */
int N;int X;cin>>N;cin>>X;
/* </foxy.memo-area> */

  dp[0][0] = mint(1);

  VM anss(N + 1);

  times(N, i) {
    times(X, j) {
      dp[j + 1][i + 1] += dp[j][i];

      if(j + 2 <= X) dp[j + 2][i + 1] += dp[j][i];
    }
  }

  // dd dp;

  // mint ans1 = 0_m, ans2 = 0_m;
  upto(0, N, i) {
    times(X, j) {
      anss[i] += dp[j][i];
    }
  }
  if(debug) cerr << '#' << __LINE__ ln
    << "  anss: " << (anss) ln
    << "  '?':  " << ('?') ln;
  upto(1, min(N / 2, (X - 1) / 2), a) {
    // dd a;
    upto(0, N - 2 * a, k) {
      // dd k; X - 1 - 2 * a; (N - 2 * a) - k; dp[X - 1 - 2 * a][(N - 2 * a) - k];
      anss[N - k] += dp[X - 1 - 2 * a][(N - 2 * a) - k];
    }
  }

  if(debug) cerr << '#' << __LINE__ ln

    << "  anss: " << (anss) ln

    << "  '*':  " << ('*') ln;
  if(X % 2 == 1 && N > (X - 1)) {
    upto(1, N - (X - 1), t) {
      anss[X - 1 + t] += 1_m; // 22...22
    }
  }

  if(debug) cerr << '#' << __LINE__ ln

    << "  anss: " << (anss) ln

    << "  '!':  " << ('!') ln;
  mint ans = 0_m;
  fact_init(N);
  times(N + 1, k) ans += anss[k] * nCk(N, k);

  cout << ans ln;
}

/* <rab:gen/> */
