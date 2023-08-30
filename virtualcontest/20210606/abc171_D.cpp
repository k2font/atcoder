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
  int N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  ll Q; cin >> Q;
  vector<ll> B(Q), C(Q); REP(i, Q) cin >> B[i] >> C[i];
  map<ll, ll> m;
  REP(i, N) m[A[i]]++;
  ll ans = 0;
  for(auto x : m) {
    if(x.second == 0) continue;
    ans += x.first * x.second;
  }
  REP(i, Q) {
    ans -= (B[i] * m[B[i]]);
    ans += (C[i] * m[B[i]]);
    m[C[i]] += m[B[i]];
    m[B[i]] = 0;
    cout << ans << endl;
  }
}