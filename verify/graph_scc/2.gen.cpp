#line 1 "base.hpp"//2
#ifndef __clang__
#pragma GCC optimize ("O3")
#endif
void solve(
#ifdef GCJ_CASE
long long case_id
#endif
);
#if defined(EBUG) && !defined(ONLINE_JUDGE)
#define debug true
#define _GLIBCXX_DEBUG
// #define _LIBCPP_DEBUG 0
#define _LIBCPP_DEBUG2 0
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
#define rep(f,t,i,c,u)for(int Rb_=(t),i=(f);i c Rb_;u(i))
#define upto(f,t,i)rep(f,t,i,<=,++)
#define uptil(f,t,i)rep(f,t,i,<,++)
#define downto(f,t,i)rep(f,t,i,>=,--)
#define downtil(f,t,i)rep(f,t,i,>,--)
#define times(n,i)uptil(0,n,i)
#define rtimes(n,i)downto((n)-1,0,i)
#define iter(v)begin(v),end(v)
#define citer(v)cbegin(v),cend(v)
#define riter(v)rbegin(v),rend(v)
#define criter(v)crbegin(v),crend(v)
#define IF(a,b,c)((a)?(b):(c))
#if debug
#define ln <<endl
#else
#define ln <<'\n'
#endif
#define tb <<'\t'
#define sp <<' '
#line 1 "base_util.hpp"//2b
#define BINOPa(t,u,op)t OP op(CS u&o)CS{RT t(*this)op##=o;}
#define CMPOP(t,op,f1,f2,x)bool OP op(CS t&x)CS{RT f1 op f2;}
#define CMPOPS(t,f1,f2,x)CMPOP(t,==,f1,f2,x)CMPOP(t,!=,f1,f2,x)\
CMPOP(t,<,f1,f2,x)CMPOP(t,<=,f1,f2,x)CMPOP(t,>,f1,f2,x)CMPOP(t,>=,f1,f2,x)
#line 1 "mod.hpp"//2b
#ifndef MOD
#define MOD 1000000007
#endif
#if !defined(FORCE_MOD)&&MOD!=1000000007&&MOD!=1000000009&&MOD!=998244353
#error mod
#endif
#line 1 "power.hpp"//2bm
TL<TN T>IL T power(T x,int n){T r(1);for(;n;n/=2){if(n%2)r*=x;x*=x;}RT r;}IL int pow_mod(int x,int n,int m){int r=1;
for(;n;n/=2){if(n%2)r=r*x%m;x=x*x%m;}RT r;}
#line 2001 "mod.hpp"//2b
IL CX int modulo(int a,int b){a%=b;RT a&&(a>0)!=(b>0)?a+b:a;}IL CX int divide(int a,int b){RT(a-modulo(a,b))/b;}
TL<int d=MOD>struct MInt{
/*!https://ei1333.github.io/luzhiled/snippets/other/mod-int.html*/
int v;CX MInt():v(0){}explicit CX MInt(int i):v(modulo(i,d)){}MInt&OP+=(CS MInt&m){v+=m.v;if(v>=d)v-=d;RT*this;}
MInt&OP-=(CS MInt&m){v-=m.v;if(v<0)v+=d;RT*this;}MInt&OP*=(CS MInt&m){v=v*m.v%d;RT*this;}MInt&OP/=(CS MInt&m){
RT*this*=m.inv();}BINOPa(MInt,MInt,+)BINOPa(MInt,MInt,-)BINOPa(MInt,MInt,*)BINOPa(MInt,MInt,/)MInt OP-()CS{
RT MInt()-=*this;}CMPOP(MInt,==,v,m.v,m)CMPOP(MInt,!=,v,m.v,m)MInt pow(int n)CS{RT power(*this,n);}MInt inv()CS{
int a=v,b=d,x=1,y=0;while(b){swap(y,x-=a/b*y);swap(b,a%=b);}RT(MInt)x;}
friend ostream&OP<<(ostream&o,CS MInt&m){RT o<<m.v;}friend istream&OP>>(istream&i,MInt&m){i>>m.v;m.v%=d;RT i;}};
using mint=MInt<>;CX mint OP"" _m(ULL n){RT mint(n);}CX MInt<998244353>OP"" _m998244353(ULL n){RT MInt<998244353>(n);}
CX MInt<1000000007>OP"" _m1e9_7(ULL n){RT MInt<1000000007>(n);}
CX MInt<1000000009>OP"" _m1e9_9(ULL n){RT MInt<1000000009>(n);}
#line 1 "typedefs.hpp"//2b
using unit = tuple<>;using int128=__int128;using LD=long double;TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;TL<TN T>using vvvec=vec<vvec<T>>;TL<TN T>using vvvvec=vec<vvvec<T>>;
using VB=vec<bool>;using VI=vec<int>;using WI=vvec<int>;using PBI=pair<bool, int>;using PBVB=pair<bool, vec<bool>>;using WPBI=vvec<pair<bool, int>>;using VS=vec<string>;
#line 1 "alias.hpp"//2b
#define EB emplace_back
#define PB push_back
#define foldl accumulate
#define scanl partial_sum
#line 1 "util.hpp"//2b
TL<TN T>IL bool amax(T&v,CS T&a){RT v<a&&(v=a,1);}TL<TN T>IL bool amin(T&v,CS T&a){RT v>a&&(v=a,1);}
TL<TN T>IL int sizeRAB(T t){RT t.size();}
#define size sizeRAB
#define clamp clampRAB
TL<TN T>IL CX CS T&clamp(CS T&a,CS T&l,CS T&r){RT a<l?l:r<a?r:a;}TL<TN V>IL void uniq2(V&v){
v.erase(unique(iter(v)),v.end());}TL<TN V>IL void uniq(V&v){sort(iter(v));uniq2(v);}
#define leftmost_ge lower_bound
#define leftmost_gt upper_bound
namespace rab{TL<TN I>IL bool is_in(I x,I l,I r){RT l<=x&&x<r;}TL<TN T>IL T fetch(CS T&d,CS vec<T>&v,int i){
RT 0<=i&&i<size(v)?v[i]:d;}}
#line 1 "debug.hpp"//2b
TL<TN T>IL istream&OP>>(istream&s,vec<T>&v){for(auto&&p:v)s>>p;RT s;}TL<TN T,TN S>
IL ostream&OP<<(ostream&s,CS pair<T,S>&p){RT s<<"("<<p.first<<","<<p.second<<")";}
#define Rdebug1(sep, ...)IL ostream& OP<<(ostream&s,CS __VA_ARGS__&v){\
int i=0;for(CS auto&e:v){i++&&s<<sep;s<<e;}RT s;}
TL<TN T>Rdebug1(' ',vec<T>)TL<TN T,TN S>Rdebug1(' ',map<T,S>)TL<TN T>Rdebug1('\n',vvec<T>)
TL<TN T,TN S>Rdebug1('\n',vec<map<T,S>>)
#line 6001 "base.hpp"//2
signed main(){if(debug)cerr<<"MOD: "<<MOD ln;else cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
auto p=setprecision(20);cout<<fixed<<p;cerr<<fixed<<p;
#ifdef GCJ_CASE
int T;cin>>T;times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
#else
solve();
#endif
RT 0;}
#line 1 "consts.hpp"//2
int di4[]={-1,0,1,0},dj4[]={0,1,0,-1},di8[]={-1,-1,0,1,1,1,0,-1},dj8[]={0,1,1,1,0,-1,-1,-1,-1},
di_knight[]={-2,-1,1,2,2,1,-1,-2},dj_knight[]={1,2,2,1,-1,-2,-2,-1};namespace dict{
[[maybe_unused]]CX char
YES[]="YES",Yes[]="Yes",yes[]="yes",NO[]="NO",No[]="No",no[]="no",WIN[]="WIN",Win[]="Win",win[]="win",
LOSE[]="LOSE",Lose[]="Lose",lose[]="lose",OK[]="OK",ok[]="ok",NG[]="NG",ng[]="ng",NA[]="NA",na[]="na",
AC[]="AC",ac[]="ac",WA[]="WA",wa[]="wa",POSSIBLE[]="POSSIBLE",Possible[]="Possible",possible[]="possible",
IMPOSSIBLE[]="IMPOSSIBLE",Impossible[]="Impossible",impossible[]="impossible",
PRIME[]="PRIME",Prime[]="Prime",prime[]="prime",
NOT_PRIME[]="NOT PRIME",Not_Prime[]="Not Prime",not_prime[]="not prime",
UNBOUNDED[]="UNBOUNDED",Unbounded[]="Unbounded",unbounded[]="unbounded",
ALICE[]="ALICE",Alice[]="Alice",alice[]="alice",BOB[]="BOB",Bob[]="Bob",bob[]="bob",
BROWN[]="BROWN",Brown[]="Brown",brown[]="brown",SAME[]="SAME",Same[]="Same",same[]="same",
DIFFERENT[]="DIFFERENT",Different[]="Different",different[]="different",
TAKAHASHI[]="TAKAHASHI",Takahashi[]="Takahashi",takahashi[]="takahashi",AOKI[]="AOKI",Aoki[]="Aoki",aoki[]="aoki";}
#line 1 "graph.hpp"//2s
TL<TN E>struct Edge{int from;int to;E weight;Edge(int from,int to,E weight):from(from),to(to),weight(weight){}
CMPOPS(Edge,make_tuple(weight,from,to),make_tuple(e.weight,e.from,e.to),e)};TL<TN E>class Graph{protected:int nv_,nde_;
public:vvec<Edge<E>>edges;Graph(int nv):nv_(nv),nde_(0),edges(nv){}IL int nv()CS{RT nv_;}IL int nde()CS{RT nde_;}
IL int nue()CS{RT nde_/2;}IL void add_dedge(int i,int j,CS E&val){if(debug&&(i<0||nv_<=i||j<0||nv_<=j)){
cerr<<"invalid index:("<<i<<","<<j<<")for Graph(nv="<<nv_<<")" ln;exit(1);}edges[i].emplace_back(i,j,val);++nde_;}
IL void add_uedge(int i,int j,CS E&val){add_dedge(i,j,val);add_dedge(j,i,val);}};
#line 1 "graph_scc.hpp"//2s
/*!https://ei1333.github.io/luzhiled/snippets/graph/strongly-connected-components.html*/
TL<TN E>struct SCCer{int n;Graph<E>scc;CS Graph<E>&g;Graph<unit>grev;VB visited;VI po,zip;WI unzip;
SCCer(CS Graph<E>&g):n(g.nv()),scc(0),g(g),grev(n),visited(n),zip(n,-1){po.reserve(n);
times(n,i)for(CS auto&e:g.edges[i]){grev.add_dedge(e.to,e.from,{});}}private:void po_dfs(int i){if(visited[i])RT;
visited[i]=1;for(CS auto&e:g.edges[i])po_dfs(e.to);po.PB(i);}void zip_rdfs(int i,int z){if(~zip[i])RT;zip[i]=z;
for(CS auto&e:grev.edges[i])zip_rdfs(e.to,z);}public:void exec(){times(n,i)po_dfs(i);int z=0;
for(auto it=po.rbegin();it!=po.rend();++it)if(zip[*it]==-1)zip_rdfs(*it,z++);scc=decltype(scc)(z);unzip.resize(z);
for(auto it=po.rbegin();it!=po.rend();++it){int x=zip[*it];unzip[x].PB(*it);for(CS auto&e:g.edges[*it]){
int y=zip[e.to];if(x!=y)assert(x<y),scc.add_dedge(x,y,e.weight);}}}};
#line 3001 "sat2.hpp"//2
IL int sat2x(int n,CS PBI&t,bool r=0){RT IF(t.first^r,t.second,t.second+n);}PBVB sat2(int n,WPBI sat){
Graph<unit>g(n*2);for(auto&ts:sat){int z=size(ts);if(z==1)g.add_dedge(sat2x(n,ts[0],1),sat2x(n,ts[0]),{});else if(z==2)
g.add_dedge(sat2x(n,ts[0],1),sat2x(n,ts[1]),{}),g.add_dedge(sat2x(n,ts[1],1),sat2x(n,ts[0]),{});
else
cerr<<"invalid sat",exit(1);}SCCer<unit>sccer(g);sccer.exec();VB ans(n);times(n,i){int x=sccer.zip[i],y=sccer.zip[i+n];
if(x==y)RT{0,{}};ans[i]=x>y;}RT{1,ans};}
#line 3001 "2.cpp"//

void solve() {
  // NN("U")
  int N;cin>>N;VS U(N);times(N,Ri_0){cin>>U[Ri_0];}

  if(N > 52 * 52 + 52) {
    cout << dict::Impossible ln;
    return;
  }

  WPBI sat;
  mint x = 2_m;
  times(N, i) times(N, j) if(i != j) {
    const auto &a = U[i], &b = U[j];

    if(i < j) {
      if(a[0] == b[0]) {
        // S[i]=S[j] if !vi && !vj
        sat.PB({{true, i}, {true, j}});
        if(a[1] == b[1]) {
          // S[i]=S[j] if vi && vj
          sat.PB({{false, i}, {false, j}});
        }
      }

      if(a[2] == b[2]) {
        // T[i]=T[j] if vi && vj
        sat.PB({{false, i}, {false, j}});
        if(a[1] == b[1]) {
          // T[i]=T[j] if !vi && !vj
          sat.PB({{true, i}, {true, j}});
        }
      }
    }

    if(a[0] == b[2]) {
      // S[i] == T[j] if !vi && vj
      sat.PB({{true, i}, {false, j}});
    }
    if(a[0] == b[1] && a[1] == b[2]) {
      // S[i] == T[j] if vi && !vj
      sat.PB({{false, i}, {true, j}});
    }
  }

  auto a = sat2(N, sat);
  if(!a.first) {
    cout << dict::Impossible ln;
    return;
  }
  times(N, i) {
    if(a.second[i]) {
      cout << U[i][0] << U[i][1] sp << U[i][2] ln;
    } else {
      cout << U[i][0] sp << U[i][1] << U[i][2] ln;
    }
  }
}
