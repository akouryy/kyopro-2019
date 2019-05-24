#line 1 "base.hpp"//1
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
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 2
#define _LIBCPP_DEBUG2 2
#define ln <<endl
#else
#define ln <<'\n'
#endif
#define tb <<'\t'
#define sp <<' '
#line 1 "base_util.hpp"//1b
#define BINOP_ASGN(t,u,op)t OP op(CS u&o)CS{RT t(*this)op##=o;}
#define CMPOP(t,op,f1,f2,x)bool OP op(CS t&x)CS{RT f1 op f2;}
#define CMPOPS(t,f1,f2,x)CMPOP(t,==,f1,f2,x)CMPOP(t,!=,f1,f2,x)\
CMPOP(t,<,f1,f2,x)CMPOP(t,<=,f1,f2,x)CMPOP(t,>,f1,f2,x)CMPOP(t,>=,f1,f2,x)
#line 1 "mod.hpp"//1b
#ifdef MOD
#if !defined(FORCE_MOD)&&MOD!=1000000007&&MOD!=1000000009&&MOD!=998244353
#error unknown mod MOD and FORCE_MOD not defined.
#endif
#else
#define MOD 1000000007
#endif
#line 1 "power.hpp"//1bm
using int128=__int128;
TL<TN T>T power(T x,int n){T rt(1);for(;n;n/=2){if(n%2)rt*=x;x*=x;}RT rt;}
int pow_mod(int x,int n,int m){int rt=1;for(;n;n/=2){if(n%2)rt=rt*x%m;x=x*x%m;}RT rt;}
int128 pow_mod_64(int128 x,int n,int m){int128 rt=1;for(;n;n/=2){if(n%2)rt=rt*x%m;x=x*x%m;}RT rt;}
#line 3001 "mod.hpp"//1b
IL CX int modulo(int a,int b){a%=b;RT a==0||(a>0)==(b>0)?a:a+b;}
IL CX int divide(int a,int b){RT(a-modulo(a,b))/b;}
TL<ULL mod=MOD>class MInt{
/*!https://ei1333.github.io/luzhiled/snippets/other/mod-int.html*/
public:int val;
CX MInt():val(0){}explicit CX MInt(int v):val(modulo(v,mod)){}
MInt&OP+=(CS MInt&m){val+=m.val;if(val>=mod)val-=mod;RT*this;}
MInt&OP-=(CS MInt&m){val-=m.val;if(val<0)val+=mod;RT*this;}MInt&OP*=(CS MInt&m){val=val*m.val%mod;RT*this;}
MInt&OP/=(CS MInt&m){val=val*m.inv().val%mod;RT*this;}
BINOP_ASGN(MInt,MInt,+)BINOP_ASGN(MInt,MInt,-)BINOP_ASGN(MInt,MInt,*)BINOP_ASGN(MInt,MInt,/)
MInt OP-()CS{MInt m;m.val=val?mod-val:0;RT m;}bool OP==(CS MInt&m)CS{RT val==m.val;}
bool OP!=(CS MInt&m)CS{RT val!=m.val;}
//MInt pow(int n)CS{MInt x(*this),rt(1);while(n){if(n%2)rt*=x;x*=x;n/=2;}RT rt;}
MInt pow(int n)CS{RT power(*this,n);}
MInt inv()CS{int a=val,b=mod,x=1,y=0,t;while(b){t=a/b;swap(b,a-=t*b);swap(y,x-=t*y);}RT(MInt)x;}
friend ostream&OP<<(ostream&o,CS MInt<mod>&m){RT o<<m.val;}
friend istream&OP>>(istream&i,MInt<mod>&m){int v;i>>v;m=MInt<mod>(v);RT i;}
};using mint=MInt<>;CX mint OP"" _m(ULL n){RT mint(n);}
CX MInt<998244353>OP"" _m998244353(ULL n){RT MInt<998244353>(n);}
CX MInt<1000000007>OP"" _m1e9_7(ULL n){RT MInt<1000000007>(n);}
CX MInt<1000000009>OP"" _m1e9_9(ULL n){RT MInt<1000000009>(n);}
#line 1 "typedefs.hpp"//1b
// struct unit{};
using unit = tuple<>;

using int128=__int128;
using LD=long double;
TL<TN T>using vec=vector<T>;
TL<TN T>using vvec=vec<vec<T>>;
TL<TN T>using vvvec=vec<vvec<T>>;
TL<TN T>using vvvvec=vec<vvvec<T>>;

using WI=vvec<int>;using VI=vec<int>;using VB=vec<bool>;
#line 1 "alias.hpp"//1b
#define EB emplace_back
#define PB push_back
#define foldl accumulate
#define scanl partial_sum
#line 1 "util.hpp"//1b
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

TL<TN V,TN W>IL void append(V&v,CS W&w){copy(citer(w),back_inserter(v));}

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

struct identity{TL<TN U>U OP()(U&&v)CS{RT v;}};
}
#line 1 "debug.hpp"//1b
TL<TN T>IL istream&OP>>(istream&s,vec<T>&v){for(auto&&p:v)s>>p;RT s;}
TL<TN T,TN S>IL ostream&OP<<(ostream&s,CS pair<T,S>&p){RT s<<"("<<p.first<<","<<p.second<<")";}
#define Rdebug1(sep, ...)IL ostream& OP<<(ostream&s,CS __VA_ARGS__&v){\
int i=0;for(CS auto&e:v){i++&&s<<sep;s<<e;}RT s;}
TL<TN T>Rdebug1(' ',vec<T>)TL<TN T,TN S>Rdebug1(' ',map<T,S>)
TL<TN T>Rdebug1('\n',vvec<T>)TL<TN T,TN S>Rdebug1('\n',vec<map<T,S>>)
#line 6001 "base.hpp"//1

signed main(){
if(debug)cerr<<"MOD: "<<MOD ln;else cin.tie(0),cerr.tie(0),ios::sync_with_stdio(0);
auto p=setprecision(20);cout<<fixed<<p;cerr<<fixed<<p;
#ifdef GCJ_CASE
int T;cin>>T;times(T,t){cout<<"Case #"<<t+1<<": ";solve(t);}
#else
solve();
#endif
RT 0;}
#line 1 "graph_scc.hpp"//1
#line 1 "uf.hpp"//1gg
TL<class T=int,class Adder=plus<T>,class Inverser=negate<T>>class UnionFind{
/*!
http://noshi91.hatenablog.com/entry/2018/05/30/191943
https://en.wikipedia.org/wiki/Disjoint-set_data_structure
https://qiita.com/drken/items/cce6fc5c579051e64fab
*/
public:int n,*parents,*sizes;T*pot_diffs;bool to_delete;
Adder adder;Inverser inverser;explicit UnionFind(int n,bool to_delete=false):
n(n),parents(new int[n]),sizes(new int[n]),pot_diffs(new T[n]),to_delete(to_delete)
{clear();}void clear(){
times(n,i)parents[i]=i;fill(sizes,sizes+n,1);fill(pot_diffs,pot_diffs+n,0);}
~UnionFind(){if(to_delete){delete[]parents;delete[]sizes;delete[]pot_diffs;}}
int size(){RT n;}int root(int i){int p=parents[i];if(p==i)RT i;
int r=root(p);pot_diffs[i]+=pot_diffs[p];RT parents[i]=r;}bool is_same(int i,int j){RT root(i)==root(j);}
bool is_all_same(){int r=root(0);uptil(1,n,i)if(root(i)!=r)RT 0;RT 1;}
bool merge(int i,int j,T pdiff=0){i=root(i);j=root(j);if(i==j)RT 0;
if(sizes[i]>sizes[j]){swap(i,j);pdiff=inverser(pdiff);}parents[i]=j;sizes[j]+=sizes[i];pot_diffs[i]=pdiff;RT 1;
}T diff(int i,int j){root(i);root(j);
RT adder(pot_diffs[i],inverser(pot_diffs[j]));}};using unionfind=UnionFind<>;
#line 2001 "graph.hpp"//1g
TL<TN E>struct Edge{int from;int to;E weight;
Edge(int from,int to,E weight):from(from),to(to),weight(weight){}
CMPOPS(Edge,make_tuple(weight,from,to),make_tuple(e.weight,e.from,e.to),e)
};TL<TN E>class Graph{protected:int nv_,nde_;unionfind uf;public:
vvec<Edge<E>>edges;Graph(int nv):nv_(nv),nde_(0),uf(nv),edges(nv){}
IL int nv()CS{RT nv_;}IL int nde()CS{RT nde_;}
IL int nue()CS{RT nde_/2;}
IL void add_dedge(int i,int j,CS E&val){if(debug&&(i<0||nv_<=i||j<0||nv_<=j)){
cerr<<"invalid index:("<<i<<","<<j<<")for Graph(nv="<<nv_<<")" ln;
exit(1);}edges[i].emplace_back(i,j,val);++nde_;
}IL void add_uedge(int i,int j,CS E&val){add_dedge(i,j,val);add_dedge(j,i,val);
}IL bool is_connected(){
uf.clear();for(CS auto&es:edges)for(CS auto&e:es)uf.merge(e.from,e.to);
RT uf.is_all_same();}};
#line 2001 "graph_scc.hpp"//1
/*!https://ei1333.github.io/luzhiled/snippets/graph/strongly-connected-components.html*/
TL<TN E>struct SCC{int n;Graph<E>scc;CS Graph<E>&g;Graph<unit>grev;VB visited;VI po,zip;
WI unzip;
SCC(CS Graph<E>&g):n(g.nv()),scc(0),g(g),grev(n),visited(n),zip(n,-1){
po.reserve(n);times(n,i)for(CS auto&e:g.edges[i]){grev.add_dedge(e.to,e.from,{});}
}private:void po_dfs(int i){if(visited[i])RT;
visited[i]=1;for(CS auto&e:g.edges[i])po_dfs(e.to);po.PB(i);}
void zip_rdfs(int i,int z){if(~zip[i])RT;zip[i]=z;for(CS auto&e:grev.edges[i])zip_rdfs(e.to,z);
}public:void exec(){times(n,i)po_dfs(i);
int z=0;for(auto it=po.rbegin();it!=po.rend();++it)if(zip[*it]==-1)zip_rdfs(*it,z++);scc=decltype(scc)(z);
unzip.resize(z);for(auto it=po.rbegin();it!=po.rend();++it){int x=zip[*it];unzip[x].PB(*it);
for(CS auto&e:g.edges[*it]){int y=zip[e.to];if(x!=y)scc.add_dedge(x,y,e.weight);}
}}};
#line 2001 "1.cpp"//

void solve() {
// NMM(ST)QQ(UV)
/* <foxy.memo-area> */
int N;int M;int Q;cin>>N;cin>>M;VI S(M);VI T(M);times(M,Ri_0){cin>>S[Ri_0];
cin>>T[Ri_0];}cin>>Q;VI U(Q);VI V(Q);times(Q,Ri_0){cin>>U[Ri_0];cin>>V[Ri_0];}
/* </foxy.memo-area> */

  Graph<unit> g(N);
  times(M, i) g.add_dedge(S[i], T[i], {});

  SCC<unit> scc(g); scc.exec();

  times(Q, i) {
    cout << (scc.zip[U[i]] == scc.zip[V[i]] ? 1 : 0) ln;
  }
}
