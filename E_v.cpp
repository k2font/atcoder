#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}

// 最大公約数
ll gcd(ll a, ll b) {
   if(b == 0) return a;
   return(gcd(b, a % b));
}

// 最小公倍数
ll lcm(ll a, ll b) {
  ll g = gcd(a, b);
  return a / g * b;
}

int main() {
  int N; cin >> N;
  vector<ll> T(N); REP(i, N) cin >> T[i];

  ll tmp = 0;
  REP(i, N) {
    if(i == 0) continue;
    if(i == 1) tmp = lcm(T[0], T[1]);
    tmp = lcm(tmp, T[i]);
  }

  cout << tmp << endl;
}