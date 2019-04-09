#define GCJ_CASE
/* <rab:include(base.hpp)> */
#pragma GCC optimize ("O3")
#ifdef GCJ_CASE
  void solve(long long case_id);
#else
  void solve(); /*  */
#endif

#if defined(EBUG) && !defined(ONLINE_JUDGE)
  #define debug true
#else
  #define NDEBUG /* <cassert>include */
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
#define int LL /* include */
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
using WI = vvec<int>; using VI = vec<int>; using VS = vec<string>; 
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
/* <rab:include(consts.hpp)> */
/* :  */
int di4[]={-1,0,1,0}, dj4[]={0,1,0,-1};
int di8[]={-1,-1,0,1,1,1,0,-1}, dj8[]={0,1,1,1,0,-1,-1,-1,-1};
int di_knight[]={-2,-1,1,2,2,1,-1,-2}, dj_knight[]={1,2,2,1,-1,-2,-2,-1};

namespace dict {
  /* \b(\w+)\[\]=\"(?!\1) */
  [[maybe_unused]] constexpr char
  YES[]="YES", Yes[]="Yes", yes[]="yes",
  NO[]="NO", No[]="No", no[]="no",
  WIN[]="WIN", Win[]="Win", win[]="win",
  LOSE[]="LOSE", Lose[]="Lose", lose[]="lose",
  OK[]="OK", ok[]="ok",
  NG[]="NG", ng[]="ng",
  NA[]="NA", na[]="na",
  AC[]="AC", ac[]="ac",
  WA[]="WA", wa[]="wa",
  POSSIBLE[]="POSSIBLE", Possible[]="Possible", possible[]="possible",
  IMPOSSIBLE[]="IMPOSSIBLE", Impossible[]="Impossible", impossible[]="impossible",
  PRIME[]="PRIME", Prime[]="Prime", prime[]="prime",
  NOT_PRIME[]="NOT PRIME", Not_Prime[]="Not Prime", not_prime[]="not prime",
  ALICE[]="ALICE", Alice[]="Alice", alice[]="alice",
  BROWN[]="BROWN", Brown[]="Brown", brown[]="brown",
  BOB[]="BOB", Bob[]="Bob", bob[]="bob",
  SAME[]="SAME", Same[]="Same", same[]="same",
  DIFFERENT[]="DIFFERENT", Different[]="Different", different[]="different",
  TAKAHASHI[]="TAKAHASHI", Takahashi[]="Takahashi", takahashi[]="takahashi",
  AOKI[]="AOKI", Aoki[]="Aoki", aoki[]="aoki";
}
/* </rab:include(consts.hpp)> */

void solve(int gcj_case_id) {
// RCHVR("X")
/* <foxy.memo-area> */
int R;int C;int H;int V;cin>>R;cin>>C;cin>>H;cin>>V;VS X(R);times(R,Ri_0){cin>>X
[Ri_0];}
/* </foxy.memo-area> */

  ++H; ++V;

  int n_choco = 0; times(R, i) times(C, j) n_choco += X[i][j] == '@';

  if(n_choco % H != 0 || n_choco / H % V != 0) {
    cout << dict::IMPOSSIBLE ln;
    if(debug) cerr << '#' << __LINE__ ln
      << "  n_choco: " << (n_choco) ln
      << "  H:       " << (H) ln
      << "  V:       " << (V) ln;
    return;
  }
  if(n_choco == 0) {
    cout << dict::POSSIBLE ln;
    return;
  }

  int np = n_choco / H / V;

  VI cuth(1, 0); cuth.reserve(H + 1);
  {
    // cut H-1

    int now_c = 0;
    times(R, i) {
      times(C, j) now_c += X[i][j] == '@';
      if(now_c == np * V) {
        cuth.push_back(i + 1);
        now_c = 0;
      } else if(now_c > np * V) {
        cout << dict::IMPOSSIBLE ln;
        if(debug) cerr << '#' << __LINE__ ln
          << "  i:      " << (i) ln
          << "  now_c:  " << (now_c) ln
          << "  np * V: " << (np * V) ln;
        return;
      }
    }

    if(size(cuth) != H + 1) {
      cout << dict::IMPOSSIBLE ln;
      if(debug) cerr << '#' << __LINE__ ln
        << "  cuth:       " << (cuth) ln
        << "  size(cuth): " << (size(cuth)) ln
        << "  H:          " << (H) ln;
      return;
    }
    // cuth.push_back(R);
  }

  VI cutv(1, 0); cutv.reserve(V + 1);
  {
    int now_c = 0;
    times(C, j) {
      times(R, i) now_c += X[i][j] == '@';
      if(now_c == np * H) {
        cutv.push_back(j + 1);
        now_c = 0;
      } else if(now_c > np * H) {
        cout << dict::IMPOSSIBLE ln;
        if(debug) cerr << '#' << __LINE__ ln
          << "  j:      " << (j) ln
          << "  now_c:  " << (now_c) ln
          << "  np * H: " << (np * H) ln;
        return;
      }
    }

    if(size(cutv) != V + 1) {
      cout << dict::IMPOSSIBLE ln;
      if(debug) cerr << '#' << __LINE__ ln
        << "  cutv:       " << (cutv) ln
        << "  size(cutv): " << (size(cutv)) ln
        << "  V:          " << (V) ln;
      return;
    }
    // cutv.push_back(C);
  }

  times(H, k) times(V, l) {
    int now_c = 0;
    uptil(cuth[k], cuth[k + 1], i) uptil(cutv[l], cutv[l + 1], j) now_c += X[i][j] == '@';
    if(now_c != np) {
      cout << dict::IMPOSSIBLE ln;
      if(debug) cerr << '#' << __LINE__ ln
        << "  k:     " << (k) ln
        << "  cuth:  " << (cuth) ln
        << "  l:     " << (l) ln
        << "  cutv:  " << (cutv) ln
        << "  now_c: " << (now_c) ln
        << "  np:    " << (np) ln;
      return;
    }
  }

  cout << dict::POSSIBLE ln;
}

/* <rab:gen/> */
