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

int main() {
  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  const ll MOD = pow(10, 9) + 7;
  ll ans = 0;
  ll res = 0; // カッコの中
  for(int i = N - 1; i >= 1; --i) {
    res += A[i];
    ll tmp2 = res % MOD;
    ll tmp = A[i - 1] * tmp2;
    tmp %= MOD;
    ans += tmp;
    ans %= MOD;
  }
  cout << ans << endl;
}