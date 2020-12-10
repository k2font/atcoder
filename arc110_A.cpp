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

// 最大公約数(ゼロ除算対策済みバージョン)
ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

// 最小公倍数
ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main() {
  ll N; cin >> N;
  ll ans = 2;
  for(int i = 2; i <= N; ++i) {
    ans = lcm(ans, i);
  }
  cout << ans + 1 << endl;
}