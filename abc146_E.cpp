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
  ll N, K; cin >> N >> K;
  vector<ll> A(N); REP(i, N) cin >> A[i];

  // 累積和を使うのはそう
  // modKで累積和を取る

  vector<ll> rui(N + 1);
  REP(i, N) rui[i + 1] = (rui[i] + A[i]) % K;
  map<ll, ll> m;
  ll ans = 0;
  queue<ll> q;
  REP(r, N + 1) {
    ll t = (rui[r] - r) % K;
    if(t < 0) t += K;
    ans += m[t];
    m[t]++;
    q.push(t);
    if(q.size() >= K) {
      m[q.front()]--; q.pop();
    }
  }
  cout << ans << endl;
}