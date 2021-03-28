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

bool IsPrime(ll num){
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (ll i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

// 最大公約数(ゼロ除算対策済みバージョン)
ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

// 最小公倍数
ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main() {
  int N; cin >> N;
  vector<ll> X(N); REP(i, N) cin >> X[i]; sort(all(X));
  // 50以下の素数の集合をつくる
  vector<ll> prime;
  for(int i = 2; i <= 50; ++i) {
    if(IsPrime(i)) prime.push_back(i);
  }

  ll ans = 2e18;

  // bit全探索する
  for(ll bit = 1; bit < (1 << prime.size()); ++bit) {
    ll tmp = 1;
    for(int i = 0; i < prime.size(); ++i) {
      if(bit & (1 << i)) {
        tmp *= prime[i];
      }
    }
    REP(i, N) {
      if(gcd(tmp, X[i]) == 1) break;
      if(i == N - 1) ans = min(ans, tmp);
    }
  }

  cout << ans << endl;
}