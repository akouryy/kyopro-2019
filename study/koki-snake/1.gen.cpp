/*? begin "base.hpp" */
#ifndef __clang__
#pragma GCC optimize ("O3")
#endif
void solve( /* この関数に問題ごとの処理を書く */
#ifdef GCJ_CASE
 long long case_id
#endif
);

#if defined(EBUG) && !defined(ONLINE_JUDGE)
 #define debug true
#else
 #define NDEBUG 
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
using LL=long long;
using ULL=unsigned long long;
#define int LL 
#define CS const
#define CX constexpr
#define IL inline
#define RT return
#define TL template
#define TN typename
#define lambda [&]
#define times(n,i) uptil(0,n,i)
#define rtimes(n,i) downto((n)-1,0,i)
#define upto(f,t,i) for(int rabT##i=(t),i=(f);i<=rabT##i;i++)
#define uptil(f,t,i) for(int rabT##i=(t),i=(f);i< rabT##i;i++)
#define downto(f,t,i) for(int rabT##i=(t),i=(f);i>=rabT##i;i--)
#define downtil(f,t,i) for(int rabT##i=(t),i=(f);i> rabT##i;i--)
#define iter(v) begin(v),end(v)
#define citer(v) cbegin(v),cend(v)
#define riter(v) rbegin(v),rend(v)
#define criter(v) crbegin(v),crend(v)
#define IF(a,b,c) ((a)?(b):(c))
#define BINOP_ASGN(t,u,op) t operator op(CS u&o)CS{RT t(*this)op##=o;}
#if debug
 #define _GLIBCXX_DEBUG
 #define _LIBCPP_DEBUG 2
 #define _LIBCPP_DEBUG2 2
 #define ln <<endl
#else
 #define ln <<'\n'
#endif
#define tb <<'\t'
#define sp <<' '
 #define PARABLE 
/*? begin "mod.hpp" */
#ifdef MOD
 #if !defined(FORCE_MOD)&&MOD!=1000000007&&MOD!=1000000009&&MOD!=998244353
  #error unknown mod MOD and FORCE_MOD not defined.
 #endif
#else
 #define MOD 1000000007
#endif
/*? begin "power.hpp" */
using int128=__int128;
TL<TN T>T power(T x,int n){T rt(1);for(;n;n/=2){if(n%2)rt*=x;x*=x;}RT rt;}
int pow_mod(int x,int n,int m){int rt=1;for(;n;n/=2){if(n%2)rt=rt*x%m;x=x*x%m;}RT rt;}
int128 pow_mod_64(int128 x,int n,int m){int128 rt=1;for(;n;n/=2){if(n%2)rt=rt*x%m;x=x*x%m;}RT rt;}
/*? end "power.hpp" */
IL CX int modulo(int a,int m){RT(a%=m,a>=0?a:a+m);}
TL<ULL mod=MOD>class MInt{
  /*! https://ei1333.github.io/luzhiled/snippets/other/mod-int.html */
public:
  int val;
  CX MInt():val(0){}
  explicit CX MInt(int v):val(modulo(v,mod)){}
  MInt&operator+=(CS MInt&m){val+=m.val;if(val>=mod)val-=mod;RT*this;}
  MInt&operator-=(CS MInt&m){val-=m.val;if(val<0)val+=mod;RT*this;}
  MInt&operator*=(CS MInt&m){val=val*m.val%mod;RT*this;}
  MInt&operator/=(CS MInt&m){val=val*m.inv().val%mod;RT*this;}
  BINOP_ASGN(MInt,MInt,+) BINOP_ASGN(MInt,MInt,-) BINOP_ASGN(MInt,MInt,*) BINOP_ASGN(MInt,MInt,/)
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
/*? end "mod.hpp" */
/*? begin "typedefs.hpp" */
struct unit{};

using int128=__int128;
using LD=long double;
TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;
TL<TN T>using vvvec=vec<vvec<T>>;
TL<TN T>using vvvvec=vec<vvvec<T>>;

//#pragma rab typedefs.dynamic
using WI = vvec<int>; using VI = vec<int>; using PII = pair<int, int>; 
/*? end "typedefs.hpp" */
/*? begin "alias.hpp" */
#define PB push_back
#define foldl accumulate
#define scanl partial_sum
/*? end "alias.hpp" */
/*? begin "util.hpp" */
TL<TN T>IL bool amax(T&v,CS T&a){RT v<a&&(v=a,true);}
TL<TN T>IL bool amin(T&v,CS T&a){RT v>a&&(v=a,true);}

#ifndef __cpp_lib_exchange_function
 #define exchange exchange_RAB
 TL<TN T,TN U=T>IL T exchange(T& t, U&& u){T x=move(t);t=forward<U>(u);RT x;}
#endif
#ifndef __cpp_lib_clamp
 #define clamp clamp_RAB
 TL<TN T>IL CX CS T&clamp(CS T&a,CS T&mn,CS T&mx){RT a<mn?mn:a>mx?mx:a;}
#endif

TL<TN T>IL int size_RAB(T t){RT t.size();}
#define size size_RAB

TL<TN V>IL void uniq_after_sort(V&v){v.erase(unique(iter(v)),v.end());}
TL<TN V>IL void sort_and_uniq(V&v){sort(iter(v));v.erase(unique(iter(v)),v.end());}
TL<TN V,TN K>IL auto leftmost_ge(CS V&v,CS K&k){RT v.lower_bound(k);}
TL<TN V,TN K>IL auto leftmost_gt(CS V&v,CS K&k){RT v.upper_bound(k);}

namespace rab{

TL<TN V,TN W>IL void append(V&v,CS W&w){copy(PARABLE citer(w),back_inserter(v));}

TL<TN V>IL auto flatten(CS V&xss,int reserve_size=0)->TN V::value_type{
  decltype(flatten(xss))ret;
  ret.reserve(reserve_size);
  for(CS auto&xs:xss)append(ret,xs);
  ret.shrink_to_fit();
  RT move(ret);
}

TL<TN I>IL bool is_in(I x,I l,I r){RT l<=x&&x<r;}

TL<TN T>IL T fetch(CS T&d,CS vec<T>&v,int i){RT 0<=i&&i<size(v)?v[i]:d;}
TL<TN T>IL T fetch(CS T&d,CS vvec<T>&v,int i,int j){
  RT 0<=i&&i<size(v)&&0<=j&&j<size(v[i])?v[i][j]:d;
}
// TL<TN T,TN U,TN...I>IL T fetch(CS T&d,CS vec<vec<U>>&v,int i,I...j){
// RT 0<=i&&i<size(v)?fetch(d,v[i],j...):d;
// }
TL<TN T>struct Compressed{int size;map<T,int>zip;vec<T>unzip;};
TL<TN T>IL Compressed<T>compressed(vec<T>v){
  sort_and_uniq(v);map<T,int>zip;times(size(v),i)zip[v[i]]=i;RT{size(v),zip,move(v)};
}
TL<TN T>struct CompressedSrc{int size;map<T,int>zip;vec<T>unzip;WI src;};
TL<TN T>IL CompressedSrc<T>compressed_src(CS vec<T>&v){
  auto c=compressed(v);VI src(c.size);times(size(v),i)src[c.zip[v[i]]].PB(i);RT{c.size,c.zip,c.unzip,src};
}

}
/*? end "util.hpp" */
/*? begin "debug.hpp" */
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
/*? end "debug.hpp" */

signed main(){
 {if(debug)cerr<<"MOD: "<<(MOD)ln;}
 if(!debug)cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
 cout<<fixed<<setprecision(20);
 cerr<<fixed<<setprecision(20);

 #ifdef GCJ_CASE
  int T;cin>>T;
  times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
 #else
  solve();
 #endif

 return 0;
}
/*? end "base.hpp" */
/*? begin "snake.hpp" */
/*!https://www.learning-algorithms.com/entry/2017/12/12/153419*/
IL void snake_zigzag_number_to_pos(int h,int w,int s,int&i,int&j){
i=s/w;j=IF(i%2==0,s%w,w-1-s%w);
}
IL PII snake_zigzag_number_to_pos(int h,int w,int s){PII p;snake_zigzag_number_to_pos(h,w,s,p.first,p.second);RT p;
}
IL int snake_zigzag_pos_to_number(int h,int w,int i,int j){RT i*w+IF(i%2==0,j,w-1-j);
}
IL void snake_cycle_number_to_pos(int h,int w,int s,int&i,int&j){
assert(h%2==0||w%2==0);bool swp=h%2;if(swp)swap(h,w);if(s==0){i=j=0;
}else if(s<=h*(w-1)){snake_zigzag_number_to_pos(h,w-1,s-1,i,j);
++j;}else{i=h*w-s;j=0;
}
if(swp)swap(i,j);
}
IL PII snake_cycle_number_to_pos(int h,int w,int s){PII p;snake_cycle_number_to_pos(h,w,s,p.first,p.second);RT p;
}
IL int snake_cycle_pos_to_number(int h,int w,int i,int j){assert(h%2==0||w%2==0);
if(h%2==1){swap(h,w);swap(i,j);
}
if(j==0){RT IF(i==0,0,h*w-i);}else{RT snake_zigzag_pos_to_number(h,w-1,i,j-1)+1;
}}
IL void snake_spath_number_to_pos(int h,int w,int i0,int j0,int s,int&i,int&j){
if(h&w&1){assert(i0%2==j0%2);if(i0%2==0){bool swp=i0==0;if(swp){swap(h,w);swap(i0,j0);swap(i,j);
}
int a0=(h-i0)*(w-j0-1),a1=h-i0,a2=i0*(w-j0);if(s<a0){snake_zigzag_number_to_pos(h-i0,w-j0-1,s,i,j);
i+=i0;j+=j0;}else if(s<a0+a1){i=h-1-(s-a0);j=w-1;
}else if(s<a0+a1+a2){snake_zigzag_number_to_pos(w-j0,i0,s-a0-a1,j,i);
i=i0-1-i;j=w-1-j;}else{snake_zigzag_number_to_pos(h,j0,s-a0-a1-a2,i,j);
j=j0-1-j;
}
if(swp)swap(i,j);}else{int a0=(h-i0)*(w-j0),a1=j0,a2=(h-1)*j0;
if(s<a0){snake_zigzag_number_to_pos(h-i0,w-j0,s,i,j);i+=i0;j+=j0;
}else if(s<a0+a1){i=h-1;j=j0-1-(s-a0);
}else if(s<a0+a1+a2){snake_zigzag_number_to_pos(j0,h-1,s-a0-a1,j,i);
i=h-2-i;}else{snake_zigzag_number_to_pos(i0,w-j0,s-a0-a1-a2,i,j);
j+=j0;
}}}else{
snake_cycle_number_to_pos(
h,w,(s+snake_cycle_pos_to_number(h,w,i0,j0))%(h*w),
i,j
);
}}
IL PII snake_spath_number_to_pos(int h,int w,int i0,int j0,int s){
PII p;snake_spath_number_to_pos(h,w,i0,j0,s,p.first,p.second);
RT p;
}
IL int snake_spath_pos_to_number(int h,int w,int i0,int j0,int i,int j){
if(h&w&1){assert(i0%2==j0%2);if(i0%2==0){if(i0==0){swap(h,w);
swap(i0,j0);swap(i,j);
}
int a0=(h-i0)*(w-j0-1),a1=h-i0,a2=i0*(w-j0);
if(j<j0){RT a0+a1+a2+snake_zigzag_pos_to_number(h,j0,i,j0-1-j);
}else if(i<i0){RT a0+a1+snake_zigzag_pos_to_number(w-j0,i0,w-1-j,i0-1-i);
}else if(j==w-1){RT a0+(h-1-i);}else{RT snake_zigzag_pos_to_number(h-i0,w-j0-1,i-i0,j-j0);
}}else{int a0=(h-i0)*(w-j0),a1=j0,a2=(h-1)*j0;if(j<j0){if(i==h-1){RT a0+(j0-1-j);
}else{RT a0+a1+snake_zigzag_pos_to_number(j0,h-1,j,h-2-i);
}}else{
if(i<i0){RT a0+a1+a2+snake_zigzag_pos_to_number(i0,w-j0,i,j-j0);
}else{RT snake_zigzag_pos_to_number(h-i0,w-j0,i-i0,j-j0);
}}}}else{
RT modulo(
snake_cycle_pos_to_number(h,w,i,j)-snake_cycle_pos_to_number(h,w,i0,j0),
h*w
);
}}
/*? end "snake.hpp" */

void solve() {
// HWNN(A)
/* <foxy.memo-area> */
int H;int W;int N;cin>>H;cin>>W;cin>>N;VI A(N);times(N,Ri_0){cin>>A[Ri_0];}
/* </foxy.memo-area> */

  WI ans(H, VI(W));

  int s = 0;
  times(N, i) times(A[i], o) {
    PII p = snake_zigzag_number_to_pos(H, W, s);
    ans[p.first][p.second] = i + 1;
    ++s;
  }

  cout << ans ln;
}
