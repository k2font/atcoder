#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
char inverse_char(char c) {
  if(isupper(c)) return tolower(c);
  else return toupper(c);
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
struct edge {
  ll to, cost;
};

// Sieve of Eratosthenes
// (*this)[i] = (divisor of i, greater than 1)
// Example: [0, 1, 2, 3, 2, 5, 3, 7, 2, 3, 2, 11, ...]
// Complexity: Space O(MAXN), Time (construction) O(MAXNloglogMAXN)
struct SieveOfEratosthenes : std::vector<ll> {
  std::vector<ll> primes;
  SieveOfEratosthenes(ll MAXN) : std::vector<ll>(MAXN + 1) {
    std::iota(begin(), end(), 0);
    for (int i = 2; i <= MAXN; i++) {
      if ((*this)[i] == i) {
        primes.push_back(i);
        for (int j = i; j <= MAXN; j += i) (*this)[j] = i;
      }
    }
  }
  using T = long long int;
  // Prime factorization for x <= MAXN^2
  // Complexity: O(log x)          (x <= MAXN)
  //             O(MAXN / logMAXN) (MAXN < x <= MAXN^2)
  std::map<T, ll> Factorize(T x) {
    // assert(x <= 1LL * (ll(size()) - 1) * (ll(size()) - 1));
    std::map<T, ll> ret;
    if (x < ll(size())) {
      while (x > 1) {
        ret[(*this)[x]]++;
        x /= (*this)[x];
      }
    }
    else {
      for (auto p : primes) {
        while (!(x % p)) x /= p, ret[p]++;
        if (x == 1) break;
      }
      if (x > 1) ret[x]++;
    }
    return ret;
  }
  std::vector<T> Divisors(T x) {
    std::vector<T> ret{1};
    for (auto p : Factorize(x)) {
      int n = ret.size();
      for (int i = 0; i < n; i++) {
        for (T a = 1, d = 1; d <= p.second; d++) {
          a *= p.first;
          ret.push_back(ret[i] * a);
        }
      }
    }
    return ret; // Not sorted
  }
  // Moebius function Table
  // return: [0=>0, 1=>1, 2=>-1, 3=>-1, 4=>0, 5=>-1, 6=>1, 7=>-1, 8=>0, ...]
  std::vector<ll> GenerateMoebiusFunctionTable() {
    std::vector<ll> ret(size());
    for (int i = 1; i < int(size()); i++) {
      if (i == 1) ret[i] = 1;
      else if ((i / (*this)[i]) % (*this)[i] == 0) ret[i] = 0;
      else ret[i] = -ret[i / (*this)[i]];
    }
    return ret;
  }
};
SieveOfEratosthenes sieve(10000000);

ll INF = 1e18; bool f = false;
ll mul(ll a, ll b) {
  if(a == 0 or b == 0) return 0;
  if(INF / a < b) f = true;
  return a * b;
}

int main() {
  ll A, B; cin >> A >> B;

	// 最小公倍数を求める
  map<ll, ll> m;
  auto x = sieve.Factorize(A);
  for(auto p : x) {
    m[p.first] = max(m[p.first], p.second);
  }

  x = sieve.Factorize(B);
  for(auto p : x) {
    m[p.first] = max(m[p.first], p.second);
  }

  ll tmp = 1;// 最小公倍数
  for(auto x : m) {
    ll t = 1;
    REP(k, x.second) t *= x.first;
    ll p = mul(tmp, t);
    tmp = p;
  }

  if(f == true) cout << "Large" << endl;
  else cout << tmp << endl;
}