#include "base.hpp"
#include "prime.hpp"
#include "math.hpp"

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

    dd j; pq; j2;

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
