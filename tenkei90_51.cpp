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
  ll N, K, P; cin >> N >> K >> P;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<vector<ll>> a1(K + 100), a2(K + 100);
  int mid = N / 2;
  for(int bit = 0; bit < (1 << mid); bit++) {
    ll tmp = 0;
    ll cnt = __builtin_popcount(bit);
    for(int i = 0; i < mid; ++i) {
      if(bit & (1 << i)) tmp += A[i];
    }
    a1[cnt].push_back(tmp);
  }

  for(int bit = 0; bit < (1 << (N - mid)); bit++) {
    ll tmp = 0;
    ll cnt = __builtin_popcount(bit);
    for(int i = 0; i < N - mid; ++i) {
      if(bit & (1 << i)) tmp += A[mid + i];
    }
    a2[cnt].push_back(tmp);
  }

  ll ans = 0;
  REP(i, K + 10) sort(all(a1[i])); REP(i, K + 10) sort(all(a2[i]));
  REP(i, K + 1) {
    REP(k, a1[i].size()) {
      ans += (lower_bound(all(a2[K - i]), P - a1[i][k] + 1) - a2[K - i].begin());
    }
  }
  cout << ans << endl;
}