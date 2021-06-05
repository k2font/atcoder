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
template <class T> T up(T a, T div) { return (a + div - 1) / div; }

map< int64_t, int > prime_factor(int64_t n) {
  map< int64_t, int > ret;
  for(int64_t i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main() {
  ll n; cin >> n;

  // nを素因数分解
  auto x = prime_factor(n);

  // nの素因数の集合を列挙し、それらの掛け算を行う。
  // その数の倍数が何個あるかを交互に足し引きする(包除原理のため)
  int ans = 0;
  for(int bit = 1; bit < (1 << x.size()); ++bit) {
    int popcnt = __builtin_popcount(bit);
    int mul = 1; int cnt = 0;
    for(auto p : x) {
      if(bit & (1 << cnt)) mul *= p.first;
      cnt++;
    }
    if(popcnt % 2 == 1) ans += n / mul;
    else ans -= n / mul;
  }

  // nから上で求めた値を引くと答え
  cout << n - ans << endl;
}