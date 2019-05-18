#define GCJ_CASE
/*?base.hpp*/
#ifndef __clang__
#pragma GCC optimize ("O3")
#endif
void solve( /*  */
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
#define OP operator
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
/*?mod.hpp*/
#ifdef MOD
 #if !defined(FORCE_MOD)&&MOD!=1000000007&&MOD!=1000000009&&MOD!=998244353
  #error unknown mod MOD and FORCE_MOD not defined.
 #endif
#else
 #define MOD 1000000007
#endif
/*?power.hpp*/
using int128=__int128;
TL<TN T>T power(T x,int n){T rt(1);for(;n;n/=2){if(n%2)rt*=x;x*=x;}RT rt;}
int pow_mod(int x,int n,int m){int rt=1;for(;n;n/=2){if(n%2)rt=rt*x%m;x=x*x%m;}RT rt;}
int128 pow_mod_64(int128 x,int n,int m){int128 rt=1;for(;n;n/=2){if(n%2)rt=rt*x%m;x=x*x%m;}RT rt;}
/*?^power.hpp*/
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
/*?^mod.hpp*/
/*?typedefs.hpp*/
struct unit{};

using int128=__int128;
using LD=long double;
TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;
TL<TN T>using vvvec=vec<vvec<T>>;
TL<TN T>using vvvvec=vec<vvvec<T>>;

//#pragma rab typedefs.dynamic
using WI = vvec<int>; using VI = vec<int>; using VB = vec<bool>; using VM = vec<mint>; 
/*?^typedefs.hpp*/
/*?alias.hpp*/
#define EB emplace_back
#define PB push_back
#define foldl accumulate
#define scanl partial_sum
/*?^alias.hpp*/
/*?util.hpp*/
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

struct identity{TL<TN U>U operator()(U&&v)CS{RT v;}};
}
/*?^util.hpp*/
/*?debug.hpp*/
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
/*?^debug.hpp*/

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
/*?^base.hpp*/
/*?graph.hpp*/
/*?uf.hpp*/
TL<class T=int,class Adder=plus<T>,class Inverser=negate<T>>
class UnionFind{
/*!
http://noshi91.hatenablog.com/entry/2018/05/30/191943
https://en.wikipedia.org/wiki/Disjoint-set_data_structure
https://qiita.com/drken/items/cce6fc5c579051e64fab
*/
public:
int n,*parents,*sizes;T*pot_diffs;bool to_delete;Adder adder;
Inverser inverser;
explicit UnionFind(int n,bool to_delete=false):
n(n),parents(new int[n]),sizes(new int[n]),pot_diffs(new T[n]),to_delete(to_delete)
{clear();
}
void clear(){
times(n,i)parents[i]=i;/*roots*/
fill(sizes,sizes+n,1);fill(pot_diffs,pot_diffs+n,0);
}
~UnionFind(){if(to_delete){delete[]parents;delete[]sizes;delete[]pot_diffs;}}
int size(){RT n;}
int root(int i){int p=parents[i];
if(p==i)RT i;/*`i`is a root*/
int r=root(p);/*and pot_diffs[p]:=diff from root*/
pot_diffs[i]+=pot_diffs[p];parents[i]=r;RT r;
}
bool is_same(int i,int j){RT root(i)==root(j);}
bool is_all_same(){int r=root(0);uptil(1,n,i)if(root(i)!=r)RT 0;RT 1;}
bool merge(int i,int j,T pdiff=0){i=root(i);j=root(j);
if(i==j)RT false;/*already merged*/
if(sizes[i]>sizes[j]){swap(i,j);pdiff=inverser(pdiff);
}
/*now sizes[i]<=sizes[j]*/
parents[i]=j;sizes[j]+=sizes[i];pot_diffs[i]=pdiff;RT true;
}
T diff(int i,int j){
root(i);/*pot_diffs[i]:=diff from root*/
root(j);/*pot_diffs[j]:=diff from root*/
RT adder(pot_diffs[i],inverser(pot_diffs[j]));}};using unionfind=UnionFind<>;
/*?^uf.hpp*/
TL<class EdgeVal>
struct Edge{int from;int to;EdgeVal weight;
Edge(int from,int to,EdgeVal weight):from(from),to(to),weight(weight){}
IL bool OP==(CS Edge&e)CS{RT weight==e.weight&&from==e.from&&to==e.to;}
IL bool OP<(CS Edge&e)CS{RT weight<e.weight||(weight==e.weight&&(from<e.from||(from==e.from&&to<e.to)));}
IL bool OP<=(CS Edge&e)CS{RT this==e||this<e;}
IL bool OP>(CS Edge&e)CS{RT e<this;}
IL bool OP>=(CS Edge&e)CS{RT e<=this;}};
TL<class VtxVal,class EdgeVal>
class Graph{
protected:
int nv_,nde_;unionfind uf;
public:
vec<VtxVal>vs;vvec<Edge<EdgeVal>>edges;
Graph(int nv):nv_(nv),nde_(0),uf(nv),vs(nv),edges(nv){}
IL int nv()CS{RT nv_;}
IL int nde()CS{RT nde_;}
IL int nue()CS{RT nde_/2;}
IL void add_dedge(int i,int j,CS EdgeVal&val){
if(debug&&(!rab::is_in(i,0LL,nv_)||!rab::is_in(j,0LL,nv_))){
cerr<<"invalid index:("<<i<<","<<j<<")for Graph(nv="<<nv_<<")" ln;
exit(1);
}
edges[i].emplace_back(i,j,val);++nde_;
}
IL void add_uedge(int i,int j,CS EdgeVal&val){add_dedge(i,j,val);
add_dedge(j,i,val);
}
IL bool is_connected(){uf.clear();
for(CS auto&es:edges)for(CS auto&e:es)uf.merge(e.from,e.to);RT uf.is_all_same();
}};
/*?^graph.hpp*/
//#include "consts.hpp"

void zp(Graph<unit, unit>& g, const VI &R, const VI &S, const VI &G, VB &par, VB &st, int i,
VB& visited) {
  if(visited[i]) return;
  if(par[i]) {
    st[i] = true;
    return;
  }
  par[i] = true;
  for(const auto &e : g.edges[i]) {
    zp(g, R, S, G, par, st, e.to, visited);
  }
  par[i] = false;
  visited[i] = true;
}

/* 0: none, 1: positive, 2: positive loop */
int zr(Graph<unit, unit>& g, const VI &R, const VI &S, const VI &G, VB &par,
       const VB &st, VI &memo, int i) {
  if(par[i]) return 0;
  if(memo[i] >= 0) return memo[i];
  par[i] = true;
  int tm = G[i] != 0;
  for(const auto &e : g.edges[i]) {
    amax(tm, zr(g, R, S, G, par, st, memo, e.to));
  }
  par[i] = false;
  if(tm == 2) return memo[i] = 2;
  if(tm == 1) return memo[i] = st[i] ? 2 : 1;
  return memo[i] = 0;
}

mint zq(Graph<unit, unit>& g, const VI &R, const VI &S, const VI &G, VB &par,
    VM &memo, VB &visited, int i) {
  if(par[i]) return 0_m;
  if(visited[i]) return memo[i];
  par[i] = true;
  memo[i] = mint(G[i]);
  for(const auto &e : g.edges[i]) {
    memo[i] += zq(g, R, S, G, par, memo, visited, e.to);
  }
  par[i] = false;
  visited[i] = true;
  return memo[i];
}

void solve(int gcj_case_id) {
// MM(-R-S)M(G)
/* <foxy.memo-area> */
int M;cin>>M;VI R(M + 1);VI S(M + 1);times(M,Ri_0){cin>>R[Ri_0];--R[Ri_0];cin>>S[Ri_0];
--S[Ri_0];}VI G(M + 1);times(M,Ri_0){cin>>G[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit, unit> g(M + 1);
  R[M] = S[M] = M;

  if(R[0]) g.add_dedge(R[0], 0, unit());
  if(S[0]) g.add_dedge(S[0], 0, unit());
  if(!R[0] && !S[0]) {
    g.add_dedge(0, 0, unit());
    g.add_dedge(0, 0, unit());
  }

  uptil(1, M, i) {
    g.add_dedge(R[i], i, unit());
    g.add_dedge(S[i], i, unit());
  }

  VB par(M), st(M), visited(M), visitedp(M);
  VI memor(M, -1);
  VM memoq(M);

  zp(g, R, S, G, par, st, 0, visitedp);
  {if(debug)cerr<<"st: "<<(st)ln;}
  if(zr(g, R, S, G, par, st, memor, 0) == 2) {
    cout << "UNBOUNDED" ln;
    return;
  }
  {if(debug)cerr<<"memor: "<<(memor)ln;}
  cout << zq(g, R, S, G, par, memoq, visited, 0) ln;
}