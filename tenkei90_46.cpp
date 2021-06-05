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

int main() {
  ll N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> B(N); REP(i, N) cin >> B[i];
  vector<ll> C(N); REP(i, N) cin >> C[i];
  ll ans = 0;

  vector<ll> ma(46), mb(46), mc(46);
  REP(i, N) ma[A[i] % 46]++;
  REP(i, N) mb[B[i] % 46]++;
  REP(i, N) mc[C[i] % 46]++;

  for(int i = 0; i < 46; ++i) {
    for(int k = 0; k < 46; ++k) {
      for(int m = 0; m < 46; ++m) {
        if((i + k + m) % 46 == 0) ans += (ll)ma[i] * mb[k] * mc[m];
      }
    } 
  }

  cout << ans << endl;
}