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

int main() {
  ll N; cin >> N;
  vector<ll> a(N), t(N); REP(i, N) cin >> a[i] >> t[i];
  ll Q; cin >> Q; vector<ll> x(Q); REP(i, Q) cin >> x[i];

  // これでは当然TLE。前処理をしたい。
  REP(i, Q) {
    ll f = x[i];
    REP(k, N) {
      if(t[k] == 1) {
        f = f + a[k];
      } else if(t[k] == 2) {
        f = max(f, a[k]);
      } else if(t[k] == 3) {
        f = min(f, a[k]);
      }
    }
    cout << f << endl;
  }
}