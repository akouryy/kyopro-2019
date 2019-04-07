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
using VI = vec<int>; using VB = vec<bool>; using HII = map<int, int>; 
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
/* <rab:include(prime.hpp)> */

/*-
  N < 2^28: brute-force
    O(√N)
  N > 2^28: Miller-Rabin primality test
    O(12(logN)^2); 64bit以上で理論的にはO((logN)^4)
  verification: OK
    yuki no.3030
      https://yukicoder.me/submissions/311870
      https://yukicoder.me/submissions/311872
*/
/*!
  https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
  http://joisino.hatenablog.com/entry/2017/08/03/210000
  https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95
*/
VI rab_prime_mr_as = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
bool is_prime(int n) {
  assert(n >= 0);
  if(n <= 3) return n >= 2;
  if(n % 2 == 0 || n % 3 == 0) return false;
  if(n < (1<<28)) {
    for(int i = 5; i * i <= n; i += 6) {
      if(n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
  } else {
    int d = n - 1, s1 = -1;
    while(d % 2 == 0) { d /= 2; ++s1; }
    for(int a : rab_prime_mr_as) {
      if(n == a) return true;
      int128 f = pow_mod_64(a, d, n);
      if(f == 1 || f == n - 1) continue;
      times(s1, r) {
        f = f * f % n;
        if(f == n - 1) goto next_a;
      }
      return false;
      next_a:;
    }
    return true;
  }
}

/* O(NloglogN) */
VB are_primes(int n) {
  assert(n >= 0);
  VB ret(n + 1, true);
  for(int j = 0; j <= n; j += 2) ret[j] = false;
  if(n > 0) ret[1] = false;
  for(int i = 3; i * i <= n; i += 2)
    if(ret[i])
      for(int j = i * i; j <= n; j += i * 2)
        ret[j] = false;
  return ret;
}

/*-
  verification: ok
  https://atcoder.jp/contests/arc004/submissions/4016291
*/
HII prime_factor(int n) {
  HII ret;
  if(n <= 1) return ret;

  #define rab_prime_factor_loop_body(x) \
    while(n % (x) == 0) { ++ret[(x)]; n /= (x); }

  rab_prime_factor_loop_body(2);
  rab_prime_factor_loop_body(3);

  for(int i = 5; i * i <= n; i += 6) {
    rab_prime_factor_loop_body(i);
    rab_prime_factor_loop_body(i + 2);
  }
  if(n > 1) ++ret[n];
  return ret;
}
/* </rab:include(prime.hpp)> */
/* <rab:include(math.hpp)> */
int gcd(int a,int b){int t;while(b)t=b,b=a%b,a=t;RT a;}
/* </rab:include(math.hpp)> */

set<signed> prime_factorS(signed n) {
  set<signed> ret;
  if(n <= 1) return ret;

  #define rab_prime_factor_loop_bodyS(x) \
    if(n % (x) == 0) { ret.insert(x); do n /= (x); while(n % (x) == 0); }

  rab_prime_factor_loop_bodyS(2);
  rab_prime_factor_loop_bodyS(3);

  for(signed i = 5; i * i <= n; i += 6) {
    rab_prime_factor_loop_bodyS(i);
    rab_prime_factor_loop_bodyS(i + 2);
  }
  if(n > 1) ret.insert(n);
  return ret;
}

void solve() {
// NMN(A)
/* <foxy.memo-area> */
signed N;signed M;cin>>N;cin>>M;VI A(N);times(N,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  // int rm = (int)sqrt(M);

  map<signed, vec<signed>> pyon;

  times(N, i) {
    auto pf = prime_factorS(A[i]);

    for(signed p : pf) {
      pyon[p].PB(i);
    }
  }

  //dd pyon[2];

  vec<signed> bns(M + 1); bns[1] = 0;

  upto(2, M, j) {
    auto pf = prime_factorS(j);
    auto x = pf.end(); --x;
    signed pq = *x;
    signed j2 = j / pq;

    /* add */
    for(signed p : pf) {
      signed k = j / p;
      if(j / p % p == 0) {
        bns[j] = bns[k]; // same because they have same factors
        goto end_j;
      }
    }
    /* /add */

    if(debug) cerr << '#' << __LINE__ ln

      << "  j:  " << (j) ln

      << "  pq: " << (pq) ln

      << "  j2: " << (j2) ln;
    bns[j] = bns[j2];

    for(signed i : pyon[pq]) {
      if(gcd(j2, A[i]) == 1) {
        // A[i] was not in bns[j2]
        ++bns[j];
      }
    }

    end_j: ;
  }

  upto(1, M, j) printf("%d\n", (signed)(N - bns[j]));
}

/* <rab:gen/> */
