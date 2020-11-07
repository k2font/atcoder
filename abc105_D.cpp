#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
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

int main() {
  int N, M; cin >> N >> M;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll ans = 0; ll res = 0;
  map<ll, ll> m; m[res]++;
  REP(i, N) {
    res += A[i];
    ll tmp = res % M; m[tmp]++;
  }
  for(auto x : m) {
    ll i = x.second;
    ans += i * (i - 1) * 0.5;
  }
  cout << ans << endl;
}
