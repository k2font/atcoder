#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
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
struct SieveOfEratosthenes : std::vector<int> {
  std::vector<int> primes;
  SieveOfEratosthenes(int MAXN) : std::vector<int>(MAXN + 1) {
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
  std::map<T, int> Factorize(T x) {
    assert(x <= 1LL * (int(size()) - 1) * (int(size()) - 1));
    std::map<T, int> ret;
    if (x < int(size())) {
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
  std::vector<int> GenerateMoebiusFunctionTable() {
    std::vector<int> ret(size());
    for (int i = 1; i < int(size()); i++) {
      if (i == 1) ret[i] = 1;
      else if ((i / (*this)[i]) % (*this)[i] == 0) ret[i] = 0;
      else ret[i] = -ret[i / (*this)[i]];
    }
    return ret;
  }
};
SieveOfEratosthenes sieve(1000000);

int N;
map<ll, int> m;

ll rec(map<ll, int>::iterator p, ll mul) {
  // 75から素因数で割っていき、p.end()にたどり着いた段階でmulが1ならそれは約数を75個持っているということ。
  // なぜなら、たとえば3*5*5=75であるため、3と5と5で割れればその約数は七五数である。
  if(p == m.end()) { // 終了条件
    if(mul == 1) return 1; // mulが1ならそれは七五数。1を加算。
    else return 0; // mulが1じゃないなら七五数ではない。
  }
  ll res = 0;
  for(int i = 0; i < p->second + 1; ++i) { // ある素因数の個数分割り算する
    if(mul % (i + 1) != 0) continue; // 指数で割り切れるものだけを採用する
    // 使用する指数(0 <= 使用できる指数の個数 <= 指数の個数の最大値)で割る
    res += rec(++p, mul / (i + 1)); // pはmapのイテレータを指す。次の素因数を見る
    --p; // 一つ進めたイテレータを戻して、次のループへ
  }
  return res;
}

int main() {
  cin >> N;
  for(int i = 1; i <= N; ++i) {
    for(auto x : sieve.Factorize(i)) m[x.first] += x.second;
  }
  cout << rec(m.begin(), 75) << endl;
}